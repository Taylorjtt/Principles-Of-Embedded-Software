/*
    main.c
    John Taylor
    Driver for Character Test Code
    gcc -std=c99 -o  char.o main.c  CharacterCodeTest.c  -Wall -Werror
*/

#include "CharacterCodeTest.h"

int main()
{
	
	int a = 0;
	while(scanf("%*c%d",&a) != EOF)
	{
		testCharacter(a);
		
	}
	return 0;
}
