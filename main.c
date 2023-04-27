#include "shell.h"

/**
* handle_condition - handles special conditions of user input
* @lineptr: input string from user
* Return: 0 on success, 1 on exit command, -1 on error
*/

int handle_condition(char *lineptr)
{
	char **argv = NULL;
	char *delim = " \t\n";
	ssize_t readline = 0;

	if (lineptr == NULL || *lineptr == '\0') /* handle empty input */
		return (0);
	readline = _strlen(lineptr);
	if (readline > 0 && lineptr[readline - 1] == '\n')
		lineptr[readline - 1] = '\0';
	argv = split_string(lineptr, delim, readline);
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
	free(lineptr);
	free(argv);
	return (0);
}
