#include "shell.h"

/**
* free_doubleP - frees double pointer.
* @argv: double pointer to an array of strings that were created
* dynamically using malloc function.
* @n: represents the number of strings in the array to free.
* Return: void
*/

void free_doubleP(char **argv, unsigned int n)
{
	unsigned int i;

	if (argv != NULL)
	{
		for (i = 0; i < n; i++)
		{
			if (argv[i] != NULL)
			free(argv[i]);
		}
		free(argv);
	}
}

/**
* free_memory - frees allocated memories.
* @tokens: pointer to an array of strings
* @valPath: pointer to a string that holds the value of PATH.
* @lineptr: pointer to user input.
* @fullPath: pointer to full path
* @flag: indicates whether fullpath was dynamically allocated
* using malloc() or not.
* Return: void
*/

void free_memory(char **tokens, char *valPath, char *lineptr,
		char *fullPath, int flag)
{
	if (valPath != NULL)
		free(valPath);
	if (tokens != NULL)
		free(tokens);
	if (lineptr != NULL)
		free(lineptr);
	if (flag == 1 && fullPath != NULL)
		free(fullPath);
}
