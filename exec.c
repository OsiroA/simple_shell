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

/**
* find_exec -  function searches directories in the PATH environment
* variable for a given command.
* @cmd: The command to search for in the PATH directories.
* @fullPath: full path of command to execute
* @path: The value of the PATH environment variable.
* Return: pointer to full path or NULL.
*/

char *find_exec(char *cmd, char *fullPath, char *path)
{
	char *token;
	struct stat st;

	if (!cmd || !path)
		return (NULL);
	/* Copy the PATH variable to a separate buffer */
	path = _strdup(path);
	if (!path)
		return (NULL);

	/* Search for the command in each directory in the PATH variable */
	token = strtok(path, ":");
	while (token)
	{
		fullPath = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (!fullPath)
		{
			free(path);
			return (NULL);
		}
		_strcpy(fullPath, token);
		_strcat(fullPath, "/");
		_strcat(fullPath, cmd);

		/* Check if the command exists in the current directory */
		if (stat(fullPath, &st) == 0)
		{
			if ((st.st_mode & S_IFMT) == S_IFREG && (st.st_mode & S_IXUSR))
			{
				/* Command found and is executable */
				free(path);
				return (fullPath);
			}
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	/* Command not found */
	free(path);
	return (NULL);
}
