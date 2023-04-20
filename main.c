#include "shell.h"

/**
* main - entry point of the program
* Return: 0 on success, -1 on failure
*/

int main(void)
{
	char *lineptr = NULL, *delim = " \t\n";
	size_t size = 0;
	ssize_t readline = 0;
	char **args;
	int i, status;

	/* the loop to keep the shell prompt infinitely running*/
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		readline = my_getline(&lineptr, &size, stdin);
		/* error handling for ctrl D*/
		if (readline == -1)
		{
			perror("exit");
			free(lineptr);
			return (-1);
		}
		readline = _strlen(lineptr);
		if (readline > 0 && lineptr[readline - 1] == '\n')
			lineptr[readline - 1] = '\0';

		args = split_string(lineptr, delim, readline);
		free(lineptr);
		lineptr = NULL;
		size = 0;

		if (args == NULL)
			return (-1);
		/* tried adding the cd path here please correct*/
		else if (args[0] == "cd")
		{
			status = _cd(args);
		}

		status = _exec(args);

		/*
		for (i = 0; args[i] != NULL; i++)
		{
			_puts(args[i]);
			free(args[i]);
		}*/

		free(args);
	}
	return (0);
}
