/*
    main.c
    John Taylor
    Utility functions to help with bit manipulations for Program 3
    gcc -std=c99 -I../IntegerRepresentation -o bitwise.o main.c ../IntegerRepresentation/IntegerRepresentation.c BitUtil.c -Wall -Werror
*/
#include <stdio.h>
#include <stdint.h>
/*
	Name:	areThreeOfTheLastFourBitsOn
	Desc:	checks if 3 of the last 4 bits are on and prints the value in binary
	Inputs: value: 16 bit value in question
	Returns:  
*/
void areThreeOfTheLastFourBitsOn(uint16_t value);

/*
	Name:	swapBytes
	Desc:	swaps the byte order in an int
	Inputs: value: 16 bit value to swapped
	Returns:swapped value
*/
uint16_t swapBytes(uint16_t value);

/*
	Name:	leftRotate
	Desc:	rotates a 16 bit integer by numberOfShifts bits
	Inputs: value: 16 bit value to shift
			numberOfShifts: number of times to shift
	Returns:shifted value
*/
uint16_t leftRotate(uint16_t value, uint8_t numberOfShifts);

/*
	Name:	leftRotate
	Desc:	rotates a 16 bit integer by numberOfShifts bits
	Inputs: value: 16 bit value to shift
			numberOfShifts: number of times to shift
	Returns:shifted value
*/
uint16_t rightRotate(uint16_t value,uint8_t numberOfShifts);