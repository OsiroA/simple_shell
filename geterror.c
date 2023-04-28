#include "shell.h"

/**
* get_error - prints error.
* @error: an int parameter used to determine which error.
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
	}
	else if (error == 3)
	{
		write(STDERR_FILENO, MALLOC_ERR, _strlen(MALLOC_ERR));
	}
	else if (error == 4)
	{
		write(STDERR_FILENO, EMPTYPATH_ERR, _strlen(EMPTYPATH_ERR));
	}
}
