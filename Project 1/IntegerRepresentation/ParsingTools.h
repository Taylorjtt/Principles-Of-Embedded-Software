/*
    ParsingTools.h
    John Taylor
    Header for tools used to aid in Parsing Input Data
    gcc -std=c99 -o  int.o main.c  ParsingTools.c IntegerRepresentation.c -Wall -Werror
*/
/*
	Name:	removeCharacter
	Desc:	Removes all occourances of a character from a char array
	Inputs: string: the string to operate on
			c: the character to remove
*/
void removeCharacter(char* string, char c);