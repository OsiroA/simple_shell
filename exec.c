#include "shell.h"

/**
* _exec - This function execute a given command with its fullpath
* @fullPath: A string that represents the fullpath
* @argv: A double pointer to a string that represents the command
* and its arguments
* Return: 0 or -1.
*/

int _exec(char *fullPath, char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		get_error(1);
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(fullPath, argv, environ) == -1)
			return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
