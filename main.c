#include "shell.h"

/**
* main - Entry point of the program.
* @argc: argument count
* @argv: argument vector (an array of strings)
* Return: 0 if SUCCESS and -1 if FAILURE
*/

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	char *delim = " \t\n";
	size_t size = 0;
	ssize_t readline = 0;
	(void)argc;

	while (1)	/* the loop to keep the shell prompt running*/
	{	write(STDOUT_FILENO, "$ ", 2);
		readline = my_getline(&lineptr, &size, stdin);
		if (readline == -1)	 /* error handling for ctrl D*/
		{	perror("exit");
			free(lineptr);
			return (-1);
		}
		readline = _strlen(lineptr);
		if (readline > 0 && lineptr[readline - 1] == '\n')
			lineptr[readline - 1] = '\0';
		argv = split_string(lineptr, delim, readline);
		free(lineptr);
		lineptr = NULL;
		size = 0;

		if (argv == NULL)
			return (-1);
		if (pipeCheck(argv))
			handle_pipes(argv);
		else
		{
		if (_strcmp(argv[0], "cd") == 0)
			cd_cmd(argv);
		else if (_strcmp(argv[0], "help") == 0)
			help_cmd();
		else if (_strcmp(argv[0], "exit") == 0)
			exit_cmd(argv);
		else
			_exec(argv);
		}
		free(argv);
	}
	free(lineptr);
	free(argv);
	return (0);
}
