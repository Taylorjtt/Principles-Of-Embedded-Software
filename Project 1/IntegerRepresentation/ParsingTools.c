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
