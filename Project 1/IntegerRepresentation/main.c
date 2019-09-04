/*
    main.c
    John Taylor
    Driver for Integer Representation Code
    GCC
*/
#define INPUT_CASE_NUMBER 12

#include "IntegerRepresentation.h"
#include "ParsingTools.h"

int main()
{

	inputCase cases[INPUT_CASE_NUMBER];

	char value[10];
	uint8_t interCaseIndex = 0;
	while(scanf("%s ",value) != EOF)
	{
		//printf("%s\n",value);
		//https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
		char * valueToken = strtok(value,",{}");

		uint8_t caseIndex = 0;
			if(interCaseIndex == 0)
		{
			printf("Value = %d, Radix = %d, OperandSize = %d\n",cases[caseIndex].value,cases[caseIndex].radix,cases[caseIndex].operandSize);
		}
		while(valueToken != NULL)
		{
			//printf("Value Token: %s\n",valueToken);
			//printf("interCaseIndex: %d\n",interCaseIndex);
			 if(interCaseIndex == 0)
			 {
			 	cases[caseIndex].value =  strtol(valueToken,NULL,0);
				interCaseIndex = interCaseIndex + 1;
			 }
			 
			else if (interCaseIndex == 1)
			{
				cases[caseIndex].radix = (uint8_t)strtol(valueToken,NULL,0);
				interCaseIndex++;
			}
			else if (interCaseIndex == 2)
			{
				cases[caseIndex].operandSize = (uint8_t)strtol(valueToken,NULL,0);
				interCaseIndex = 0;
				caseIndex++;
			}
			
			valueToken = strtok(NULL,",{}");

			
		}



	}


	return 0;
}