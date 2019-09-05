/*
    IntegerRepresentation.c 
    John Taylor
    gcc -std=c99 -o  int.o main.c  ParsingTools.c IntegerRepresentation.c -Wall -Werror
*/
#include "IntegerRepresentation.h"

bool isValidRadix(uint8_t radix)
{
    if(radix == 8 || radix == 10 || radix == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidOperandSize(uint8_t operandSize)
{
    if(operandSize == 4 || operandSize == 8 || operandSize == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int maxAbsoluteValue(uint8_t bits)
{
    //2^(bits)-1
    return (1<<bits) - 1;
}
int minOnesComplement(uint8_t bits)
{
   //2^(bits-1) - 1
    return -maxComplement(bits);
}
int maxComplement(uint8_t bits)
{
     //max ones and twos complement and sign magnitude is the same
      //2^(bits-1) -1
    return (1<<(bits - 1)) -1;
}
int minTwosComplement(uint8_t bits)
{
     //-2^(bits-1)
     return -(maxComplement(bits)+1);
}

void printHeader(int32_t value, uint8_t radix, uint8_t operandSize)
{
    if(radix == 8)
    {
        printf("Input:\tValue 0%o\tRadix %d \tOperand Size %d\n",value, radix,operandSize);
    }
    
    else if (radix == 16)
    {
        printf("Input:\tValue 0x%X\tRadix %d \tOperand Size %d\n",value, radix,operandSize);
    }
    else
    {
        printf("Input:\tValue %d\tRadix %d \tOperand Size %d\n",value, radix,operandSize);
    }
    if(operandSize == 4)
    {
        printf("Output:\t\t\t\tValue\t\tMaximum\t\tMinimum\n");
    }
    else if (operandSize == 8)
    {
        printf("Output:\t\t\t\tValue\t\tMaximum\t\tMinimum\n");
    }
    else if (operandSize == 16)
    {
        printf("Output:\t\t\t\tValue\t\t\tMaximum\t\t\tMinimum\n");
    }
    
}
void printBinary(int32_t value, uint8_t operandSize)
{
    //add 3 extra chars for "0b and the null terminator /0"
    char valueBuffer[operandSize + 3];
    char minBuffer[operandSize + 3];
    char maxBuffer[operandSize + 3];
    integerToBinary(maxAbsoluteValue(operandSize),maxBuffer,operandSize);
    
    integerToBinary(0,minBuffer,operandSize);
    if(abs(value) > maxAbsoluteValue(operandSize))
    {
        strncpy(valueBuffer,"> Error\t",operandSize+3);
    }
    else
    {
        integerToBinary(abs(value), valueBuffer, operandSize);
    }
    
    
    if(operandSize == 4)
    {
        printf("Binary(abs)\t\t\t%s\t\t%s\t\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 8)
    {
        printf("Binary(abs)\t\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 16)
    {
        printf("Binary(abs)\t\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    
}
void printOctal(int32_t value, uint8_t operandSize)
{
    if(abs(value) > maxAbsoluteValue(operandSize))
    {
        printf("Octal(abs)\t\t\t> Error\t\t0%o\t\t%o\n",maxAbsoluteValue(operandSize),0);
    }
    else
    {
        if(operandSize == 16)
        {
            printf("Octal(abs)\t\t\t0%o\t\t\t0%o\t\t\t%o\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        else
        {
            printf("Octal(abs)\t\t\t0%o\t\t0%o\t\t%o\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        
    }

    
}
void printDecimal(int32_t value, uint8_t operandSize)
{
    if(abs(value) > maxAbsoluteValue(operandSize))
    {
        printf("Decimal(abs)\t\t\t> Error\t\t%d\t\t%d\n",maxAbsoluteValue(operandSize),0);
    }
    else
    {
        if(operandSize == 16)
        {
            printf("Decimal(abs)\t\t\t%d\t\t\t%d\t\t\t%d\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        else
        {
            printf("Decimal(abs)\t\t\t%d\t\t%d\t\t%d\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        
    }
}
void printHex(int32_t value, uint8_t operandSize)
{
    if(abs(value) > maxAbsoluteValue(operandSize))
    {
        printf("Hex(abs)\t\t\t> Error\t\t0x%X\t\t0x%X\n",maxAbsoluteValue(operandSize),0);
    }
    else
    {
        if(operandSize == 16)
        {
           printf("Hex(abs)\t\t\t0x%X\t\t\t0x%X\t\t\t0x%X\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        else
        {
            printf("Hex(abs)\t\t\t0x%X\t\t0x%X\t\t0x%X\n",abs(value),maxAbsoluteValue(operandSize),0);
        }
        
    }
}
void printOnesComplement(int32_t value, uint8_t operandSize)
{
    //numbers are stored in twos compliment therefore we must subtract 1 to convert to ones compliment if the number is negative
    if(value < 0)
    {
        value-=1;
    }
    //add 3 extra chars for "0b and the null terminator /0"
    char valueBuffer[operandSize + 3];
    char minBuffer[operandSize + 3];
    char maxBuffer[operandSize + 3];
    
    integerToBinary(maxComplement(operandSize),maxBuffer,operandSize);
    
    //numbers are stored in twos compliment therefore we must subtract 1 to convert to ones compliment if the number is negative
    integerToBinary(minOnesComplement(operandSize)-1,minBuffer,operandSize);
    
    if(value > maxComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"> Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"> Error\t",operandSize+3);
        }
    }
    else if(value < minOnesComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"< Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"< Error\t",operandSize+3);
        }
    }
    else
    {
        integerToBinary(value, valueBuffer, operandSize);
    }
    if(operandSize == 4)
    {
         printf("Signed One's Compliment\t\t%s\t\t%s\t\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 8)
    {
         printf("Signed One's Compliment\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 16)
    {
        printf("Signed One's Compliment\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
   
}
void printTwosComplement(int32_t value, uint8_t operandSize)
{

    //add 3 extra chars for "0b and the null terminator /0"
    char valueBuffer[operandSize + 3];
    char minBuffer[operandSize + 3];
    char maxBuffer[operandSize + 3];
    
    integerToBinary(maxComplement(operandSize),maxBuffer,operandSize);

    integerToBinary(minTwosComplement(operandSize),minBuffer,operandSize);
    // printf("value %d, Max %d",value, maxComplement(operandSize));
    if(value > maxComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"> Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"> Error\t",operandSize+3);
        }
    }
    else if(value < minTwosComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"< Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"< Error\t",operandSize+3);
        }
    }
    else
    {
        integerToBinary(value, valueBuffer, operandSize);
    }
    if(operandSize == 4)
    {
        printf("Signed Two's Compliment\t\t%s\t\t%s\t\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 8)
    {
         printf("Signed Two's Compliment\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 16)
    {
        printf("Signed Two's Compliment\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    
}
void printSignMagnitude(int32_t value, uint8_t operandSize)
{
    int32_t twosComplementValue = value;
    if(value < 0)
    {
        //http://www.cs.umd.edu/~meesh/cmsc311/links/handouts/numbers/node7.html
        //convert from twos compliment to sign magnitude if the number is negative
        value = (~value + 1);
        value = value | (1<<(operandSize-1));

    }
     //add 3 extra chars for "0b and the null terminator /0"
    char valueBuffer[operandSize + 3];
    char minBuffer[operandSize + 3];
    char maxBuffer[operandSize + 3];
    
    integerToBinary(maxComplement(operandSize),maxBuffer,operandSize);

    //format the minimum as a sign maginitude representation
    uint32_t min = ~minOnesComplement(operandSize) + 1;
    min = min | (1<<(operandSize-1));
    integerToBinary(min,minBuffer,operandSize);

    if(twosComplementValue > maxComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"> Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"> Error\t",operandSize+3);
        }
       
    }
    else if(twosComplementValue < minOnesComplement(operandSize))
    {
        if(operandSize == 16)
        {
            strncpy(valueBuffer,"< Error\t\t",operandSize+3);
        }
        else
        {
             strncpy(valueBuffer,"< Error\t",operandSize+3);
        }
        
    }
    else
    {
        integerToBinary(value, valueBuffer, operandSize);
    }
    if(operandSize == 4)
    {
        printf("Sign-Magnitude\t\t\t%s\t\t%s\t\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 8)
    {
          printf("Sign-Magnitude\t\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
    else if (operandSize == 16)
    {
        printf("Sign-Magnitude\t\t\t%s\t%s\t%s\n",valueBuffer,maxBuffer,minBuffer);
    }
   
}

void printTable(int32_t value, uint8_t radix, uint8_t operandSize)
{
    printBinary(value,operandSize);
    printOctal(value,operandSize);
    printDecimal(value,operandSize);
    printHex(value,operandSize);
    printOnesComplement(value,operandSize);
    printTwosComplement(value,operandSize);
    printSignMagnitude(value,operandSize);
    printf("\n\n");
}
void integerToBinary(int32_t a, char *buffer, uint8_t operandSize)
{
    //https://stackoverflow.com/questions/1024389/print-an-int-in-binary-representation-using-c
    //go to the end of the buffer
   
    buffer[0] = '0';
    buffer[1] = 'b';
    
    for(int i = operandSize + 1; i >= 2; i--)
    {
        
        //get the rightmost bit
        buffer[i] = (a & 1) + '0';
        //shift the value right
        a >>= 1;
    }
    
    buffer[operandSize + 2] = '\0';
    
   

}






