#include "shell.h"

/**
* _exec - This function executes a function,
* checks for builtins and launches the process
* @args: arguments
* Return: 1 if success
*/
int _exec(char **args)
{
	pid_t childprocess;
	int a;

	childprocess = fork();

	/* error handling for if the execve fails*/
	if (childprocess == 0)
	{
		execve(args[0], args, environ);
		perror("./shell");
		exit(1);
	}
	/* telling the parent process to wait for the child process*/
	else if (childprocess > 0)
	{
		wait(&a);
		if (WIFEXITED(a))
		{
			return (1);
		}
		else
		{
			perror("Child process terminated abnormally");
			return (-1);
		}
	}
	/* error handling for if forking fails*/
	else
	{
		perror("Couldn't fork");
		return (-1);
	}
	return (1);
}
