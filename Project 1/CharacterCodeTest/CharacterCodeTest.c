/*
    CharacterCodeTest.c
    John Taylor
    implementation file for character test code
    gcc -std=c99 -o  char.o main.c  CharacterCodeTest.c  -Wall -Werror
*/
#include "CharacterCodeTest.h"

void testCharacter(uint8_t characterCode)
{
	if(characterCode >= MIN_LOWER_CASE && characterCode <= MAX_LOWER_CASE)
	{
		printf("Code: %d\tType: Lower Case\tASCII Char:%c\n",characterCode,characterCode);
	}
	if(characterCode >= MIN_UPPER_CASE && characterCode <= MAX_UPPER_CASE)
	{
		printf("Code: %d\tType: Upper Case\tASCII Char:%c\n",characterCode,characterCode);
	}
	if(characterCode >= MIN_DIGIT && characterCode <= MAX_DIGIT)
	{
		printf("Code: %d\tType: Digit\tASCII Char:%c\n",characterCode,characterCode);
	}
	if((characterCode >= MIN_WHITESPACE && characterCode <= MAX_WHITESPACE) || characterCode == DEL)
	{
		printf("Code: %d\tType: White Space\tASCII Char:%c\n",characterCode,characterCode);
	}
}