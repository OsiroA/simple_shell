#include "shell.h"

/**
* find_command - function to search for a command in the PATH.
* @cmd: pointer to a string.
* Return: the full path of the command.
*/

char *find_command(char *cmd)
{
	char *dir = NULL, *fullPath = NULL;
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		perror("PATH not found");
		exit(EXIT_FAILURE);
	}
	dir = _strtok(path, ":");
	while (dir != NULL)
	{
		fullPath = malloc(_strlen(dir) + _strlen(cmd) + 2);
		_strcpy(fullPath, dir);
		_strcat(fullPath, "/");
		_strcat(fullPath, cmd);
		if (access(fullPath, X_OK) == 0)
		{
			free(cmd);
			return (fullPath);
		}
		free(fullPath);
		dir = _strtok(NULL, ":");
	}
	perror("command not found");
	exit(EXIT_FAILURE);
}

/**
* _exec -  Function to execute a command with arguments.
* @args: pointer to an array of strings.
* Return: integer status code or -1
*/

int _exec(char **args)
{
	pid_t pid;
	int status;
	char *cmd = NULL, *fullPath = NULL;

	pid = fork();
	if (pid == 0)
	{	/* child process */
		if (access(args[0], X_OK) == 0)
		{	/* execute the command using execve */
			execve(args[0], args, environ);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		else
		{	/* find the command in the PATH */
			cmd = _strdup(args[0]);
			fullPath = find_command(cmd);
			/* execute the command using execve */
			execve(fullPath, args, environ);
			perror(fullPath);
			free(fullPath);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{	/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		return (-1);
	return (status);
}
