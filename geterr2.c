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
