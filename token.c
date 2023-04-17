#include "shell.h"
/**
* _strtok - This function tokenises a string
* @ptrtostr: the pointer to the string to be tokenized
* @delimiter: This specifies where to break the
* string each time the function is called
* Return: the token broken off
*/
char *_strtok(char *ptrtostr, char *delimiter)
{
	static char *positionptr;
	char *tokenstarts;

	if (ptrtostr != NULL)
	{
		positionptr = ptrtostr;
	}

	if (positionptr == NULL || *positionptr == '\0')
	{
		return (NULL);
	}

	tokenstarts = positionptr;

	while (*positionptr != *delimiter && *positionptr != '\0')
	{
		positionptr++;
	}
	if (*positionptr == *delimiter)
	{
		*positionptr = '\0';
		positionptr++;
	}
	return (tokenstarts);
}
