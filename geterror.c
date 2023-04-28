#include "shell.h"

/**
* get_error - prints error.
* @error: a string parameter used to determine which error.
* Return: void
*/

void get_error(int error)
{
	if (error == 1)
	{
		write(STDERR_FILENO, FORK_ERR, _strlen(FORK_ERR));
		perror("Error");
	}
	else if (error == 2)
	{
		perror("Error");
	else if (error == 3)
	{
		write(STDERR_FILENO, MALLOC_ERR, _strlen(MALLOC_ERR));
	}
	else if (error == 4)
	{
		write(STDERR_FILENO, EMPTYPATH_ERR, _strlen(EMPTYPATH_ERR));
	}
}

/**
* free_memory - frees allocated memories.
* @tokens: pointer to an array of strings
* @vaPa: pointer to a string that holds the value of PATH.
* @lptr: pointer to user input.
* @fulPa: pointer to full path
* @flag: indicates whether fullpath was dynamically allocated using malloc().
* Return: void
*/

void free_memory(char **tokens, char *vaPa, char *lptr, char *fulPa, int flag)
{
	if (vaPa != NULL)
		free(vaPa);
	if (tokens != NULL)
		free(tokens);
	if (lptr != NULL)
		free(lptr);
	if (flag == 1 && fulPa != NULL)
		free(fulPa);
}
