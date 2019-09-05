/*
    CharacterCodeTest.h
    John Taylor
    Header file for character test code
    gcc -std=c99 -o  char.o main.c  CharacterCodeTest.c  -Wall -Werror
*/
#include <stdint.h>
#include <stdio.h>

/*
  Minimum and Maximum numerical values that segregate ASCII Types
*/
#define MIN_LOWER_CASE (97)
#define MAX_LOWER_CASE (122)

#define MIN_UPPER_CASE (65)
#define MAX_UPPER_CASE (90)

#define MIN_DIGIT (48)
#define MAX_DIGIT (57)

#define MIN_WHITESPACE (0)
#define MAX_WHITESPACE (32)
#define DEL (127)


/*
	Name:	testCharacter
	Desc:	given a character code, this function will print to standard output the Code
			the type {Upper Case, Lower Case, Digit, White Space or Special} and the ASCII
			char for that character
	Inputs: characterCode: code to process
*/
void testCharacter(uint8_t characterCode);
