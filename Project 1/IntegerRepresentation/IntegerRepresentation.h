/*
    IntegerRepresentation.h 
    John Taylor
    gcc -std=c99 -o  int.o main.c  ParsingTools.c IntegerRepresentation.c -Wall -Werror
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct inputCase inputCase;
struct inputCase
{
	int32_t value;
	uint8_t radix;
	uint8_t operandSize; 
};

/*
//Data Validation
*/

/*
	Name:	isValidRadix
	Desc:	checks if the radix is 8, 10 or 16
	Inputs: the radix in question
	Returns: true or false based 
*/
bool isValidRadix(uint8_t radix);
/*
	Name:	isValidOperandSize
	Desc:	checks if the operand size is 4, 8 or 16
	Inputs: the operand size in question
	Returns: true or false based 
*/
bool isValidOperandSize(uint8_t operandSize);

/*
//Generic functions for Calculating Mins and Maxes based on operand size
*/

/*
	Name:	minOnesComplement
	Desc:	calculates the minimum number that can be represented by a one's compliment number with 'bits' number of bits
	Inputs: bits: number of bits in the operand
	Returns: the smallest integer that can be represented
*/
int32_t minOnesComplement(uint8_t bits);


/*
	Name:	maxComplement
	Desc:	calculates the maximum number that can be represented by a one's or two's compliment number or a Signed Magnitude number
	Inputs: bits: number of bits in the operand
	Returns: the largest integer that can be represented
*/
int32_t maxComplement(uint8_t bits);


/*
	Name:	minTwosComplement
	Desc:	calculates the minimum number that can be represented by a twos's compliment number with 'bits' number of bits
	Inputs: bits: number of bits in the operand
	Returns: the smallest integer that can be represented
*/
int32_t minTwosComplement(uint8_t bits);


/*
	Name:	maxAbsoluteValue
	Desc:	calculates the maximum positive number that can be represented by an unsigned number with 'bits' number of bits
	Inputs: bits: number of bits in the operand
	Returns: the largest integer that can be represented
*/
int32_t maxAbsoluteValue(uint8_t bits);

/*
//Functions to print the table
*/

/*
	Name:	printHeader
	Desc:	prints the inputs and the table header
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printHeader(int32_t value,uint8_t radix,uint8_t operandSize);

/*
	Name:	printBinary
	Desc:	prints the binary line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printBinary(int32_t value, uint8_t operandSize);

/*
	Name:	printOctal
	Desc:	prints the octal line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printOctal(int32_t value, uint8_t operandSize);

/*
	Name:	printDecimal
	Desc:	prints the decimal line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printDecimal(int32_t value, uint8_t operandSize);

/*
	Name:	printHex
	Desc:	prints the hex line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printHex(int32_t value, uint8_t operandSize);

/*
	Name:	printOnesComplement
	Desc:	prints the One's Compliment line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printOnesComplement(int32_t value, uint8_t operandSize);
/*
	Name:	printTwosComplement
	Desc:	prints the Two's Compliment line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printTwosComplement(int32_t value, uint8_t operandSize);
/*
	Name:	printSignMagnitude
	Desc:	prints the Sign-Magnitude line of the table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printSignMagnitude(int32_t value, uint8_t operandSize);
/*
	Name:	printTable
	Desc:	consolidation function that prints the entire table
	Inputs: value: value to be displayed
			radix: radix to use
			operandSize: the operand size
	Returns: 
*/
void printTable(int32_t value, uint8_t radix, uint8_t operandSize);

/*
	Name:	integerToBinary
	Desc:	converts an integer to a binary representation in char array form
	Inputs: a: value to convert
			buffer: buffer to store binary representation in
			operandSize: the operand size
	Returns: 
*/
void integerToBinary(int32_t a, char * buffer, uint8_t operandSize);

