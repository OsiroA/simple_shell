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
		execve(args[0], av, NULL);
		perror("Execve failed");
		exit(1);
	}
	/* telling the parent process to wait for the child process*/
	else if (childprocess > 0)
	{
		wait(&a);
		if (WIFEXITED(a))
		{
			_puts("Child process exited with status: %d\n", WEXITSTATUS(a));
			return (1);
		}
		else
		{
			_puts("Child process terminated abnormally\n");
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

int main(void)
{
	int result;

	/* Prepare the arguments to be passed to our_exec()*/
	char *args[] = {"/bin/ls", "-l", NULL};
	/*Example: execute "ls -l" command*/

	/* Call our_exec() with the arguments*/
	result = _exec(args);

	/* Check the return value of our_exec()*/
	if (result == 1)
	{
		printf("Command executed successfully\n");
	}
	else if (result == -1)
	{
		printf("Failed to execute command\n");
	}

	return (0);
}
