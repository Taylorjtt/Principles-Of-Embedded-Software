/*
    main.c
    John Taylor
    Utility functions to help with bit manipulations for Program 3
    gcc -std=c99 -I../IntegerRepresentation -o bitwise.o main.c ../IntegerRepresentation/IntegerRepresentation.c BitUtil.c -Wall -Werror
*/
#include "BitUtil.h"
#include "IntegerRepresentation.h"

uint16_t swapBytes(uint16_t value)
{
	return (value << 8) | (value >> 8);
}
uint16_t leftRotate(uint16_t value,uint8_t numberOfShifts)
{
	//assumes a 16 bit integer
	//https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
	return (value << numberOfShifts) | (value >> (16 - numberOfShifts));
}
uint16_t rightRotate(uint16_t value,uint8_t numberOfShifts)
{
	//assumes a 16 bit integer
	//https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
	return (value >> numberOfShifts) | (value << (16 - numberOfShifts));
}
void areThreeOfTheLastFourBitsOn(uint16_t value)
{
	char binaryRepresentation[16];
	integerToBinary(value,binaryRepresentation,16);
	printf("Binary: %s\n",binaryRepresentation);
	//testing if 3 of the last 4 bits are on (I assume he means 3 of the last 4 LSB's)

	//mask off everyting but the last 4 bits
	uint16_t tempValue = value & 0xF;
	uint8_t count = 0;
	for(int i = 0; i < 4; i++)
	{
		//count the number of bits that are on
		count += tempValue & 1;
		tempValue >>=1;
	}
	//print the result of the test
	if(count >= 3)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
}