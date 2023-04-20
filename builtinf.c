#include "shell.h"

/**
* cd_cmd - this function changes the directory.
* @args: arguments passed.
* Return: void
*/

void cd_cmd(char **args)
{
	if (args[0] == NULL)
	{
		perror("cd: missing argument\n");
	}
	else if (chdir(args[0]) == -1)
	{
		perror("cd");
	}
}

/**
* exit_cmd - this function is a builtin function to exit the shell.
* @args: arguments passed.
*Return: void
*/

void exit_cmd(char **args)
{
	int status = 0;

	/* Check if an exit status was provided as an argument */
	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}

	free(args);
	exit(status);
}

/**
* help_cmd - This function shows the list of available builtins when called.
* Return: Void
*/

void help_cmd(void)
{
	char *helptext = "Simple Shell Help:\n"
			"cd [directory] - Change the current working directory.\n"
			"exit - Exit the shell.\n"
			"help - Show this help message.\n";
	int len = _strlen(helptext);

	if (write(STDOUT_FILENO, helptext, len) != len)
	{
		perror("Error writing to stdout");
	}
}
