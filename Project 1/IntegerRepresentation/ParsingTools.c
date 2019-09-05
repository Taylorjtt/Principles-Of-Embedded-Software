/*
    ParsingTools.c
    John Taylor
    Implementation for for tools used to Aid in Parsing Input Data
    gcc -std=c99 -o  int.o main.c  ParsingTools.c IntegerRepresentation.c -Wall -Werror
*/
void removeCharacter(char* string, char c)
{
	//https://stackoverflow.com/questions/9895216/how-to-remove-all-occurrences-of-a-given-character-from-string-in-c
	char *writePointer = string;
	char *readPointer = string;

	while(*readPointer)
	{
		*writePointer = *readPointer++;
		writePointer += (*writePointer != c);
	}
	*writePointer = '\0';
}
