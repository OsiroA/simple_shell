#include "shell.h"

/**
* main - entry point of the program
* Return: 0 on success, -1 on failure
*/

int main(void)
{
	char *lineptr = NULL;
	size_t size = 0;
	ssize_t readline = 0;
	char **args;
	int i;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		readline = my_getline(&lineptr, &size, stdin);
		if (readline == -1)
		{
			perror("exit");
			free(lineptr);
			return (-1);
		}
		readline = _strlen(lineptr);
		if (readline > 0 && lineptr[readline - 1] == '\n')
			lineptr[readline - 1] = '\0';

		args = split_string(lineptr, " ", readline);
		free(lineptr);
		lineptr = NULL;
		size = 0;

		if (args == NULL)
			return (-1);

		for (i = 0; args[i] != NULL; i++)
		{
			_puts(args[i]);
			free(args[i]);
		}
		free(args);
	}
	return (0);
}
