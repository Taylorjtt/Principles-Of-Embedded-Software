/*
    main.c
    John Taylor
    Driver for Integer Representation Code
    gcc -std=c99 -o  int.o main.c  ParsingTools.c IntegerRepresentation.c -Wall -Werror
*/
#define INPUT_CASE_NUMBER (11)

#include "IntegerRepresentation.h"
#include "ParsingTools.h"

int main()
{

	inputCase cases[INPUT_CASE_NUMBER];

	char input[10];

	int32_t caseNumber = 0;
	int32_t interCaseIndex = 0;

	//parse the input file
	while(scanf("%s",input) != EOF)
	{
		/*
			Take out all of the delimiting characters
		*/
		removeCharacter(input, '{');
		removeCharacter(input, '}');
		removeCharacter(input, ',');
		removeCharacter(input, ' ');

		//printf("%s\n",input);

		if(interCaseIndex == 0)
		{
			cases[caseNumber].value = strtol(input,NULL,0);
			interCaseIndex++;
		}
		else if(interCaseIndex == 1)
		{
			cases[caseNumber].radix = strtol(input,NULL,0);
			interCaseIndex++;
		}
		else if(interCaseIndex == 2)
		{
			cases[caseNumber].operandSize = strtol(input,NULL,0);
			interCaseIndex = 0;
			caseNumber++;
		}
		
	}

	for(int i = 0; i < INPUT_CASE_NUMBER; i++)
	{
		//printf("Case # %d\tValue: %d\tRadix: %d\tOperandSize: %d\n",i,cases[i].value,cases[i].radix,cases[i].operandSize);
		printHeader(cases[i].value,cases[i].radix,cases[i].operandSize);
		if(isValidRadix(cases[i].radix))
		{
			if(isValidOperandSize(cases[i].operandSize))
			{
				printTable(cases[i].value,cases[i].radix,cases[i].operandSize);
			}
			else
			{
			printf("Invalid Operand Size\n");
			printf("\n");
			}
			
		}
		else
		{
			printf("Invalid Radix\n");
			printf("\n");
		}
	}


	return 0;
}