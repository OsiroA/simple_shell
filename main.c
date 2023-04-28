#include "shell.h"

/**
* prompt - checks for interactive mode and write prompt
* to standard output.
* Return: void
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
* main - Entry point of the shell program.
* Return: 0 always
*/

int main(int argc, char **argv)
{
	char *path, *fullPath, *lineptr;
	int builtinf_status, status, flag;
	(void)argc;

	path = fullPath = lineptr = NULL;

	while (1)
	{
		prompt();
		lineptr = _readline(stdin);
		if (_strcmp(lineptr, "\n", 1) == 0)
		{	free(lineptr);
			continue;
		}
		argv = split_string(lineptr);
		if (argv[0] == NULL)
			continue;
		builtinf_status = exe_builtinf(argv);
		if (builtinf_status == 0 || builtinf_status == -1)
		{
			free(argv);
			free(lineptr);
		}
		if (builtinf_status == 0)
			continue;
		if (builtinf_status == -1)
			exit(0);

		flag = 0;
		path = _getenv("PATH");
		fullPath = find_exec(argv[0], fullPath, path);
		if (fullPath == NULL)
		{
			fullPath = argv[0];
		}
		else
		{
			flag = 1;
		}

		status = _exec(fullPath, argv);
		if (status == -1)
			get_error(2);
		free_memory(argv, path, lineptr, fullPath, flag);
	}
	return (0);
}
