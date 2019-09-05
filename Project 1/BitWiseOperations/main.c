/*
    main.c
    John Taylor
    Bitwise Operations Driver
    gcc -std=c99 -I../IntegerRepresentation -o bitwise.o main.c ../IntegerRepresentation/IntegerRepresentation.c BitUtil.c -Wall -Werror

*/
#include "BitUtil.h"


int main()
{
	uint16_t value = 0xCAFE;

	//print in hex
	printf("Initial Value: 0x%X\n",value);

	areThreeOfTheLastFourBitsOn(value);

	value = swapBytes(value);

	printf("Swapped Value: 0x%X\n",value);
	areThreeOfTheLastFourBitsOn(value);

	value = leftRotate(value,4);
	areThreeOfTheLastFourBitsOn(value);

	value = rightRotate(value,8);
	areThreeOfTheLastFourBitsOn(value);

	return 0;
}

