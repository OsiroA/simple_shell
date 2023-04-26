#include "shell.h"

/**
* handle_pipe - This function handles a pipe command in the shell.
* @argv1: contains the arguments for the command to be executed on the
* left side of the pipe.
* @argv2: contains the arguments for the command to be executed on the
* right side of the pipe.
* Return: void.
*/

void handle_pipe(char **argv1, char **argv2)
{
	int pfd[2];
	pid_t pid1, pid2;
	int status;

	if (pipe(pfd) == -1)
	{
		perror("pipe");
		return;
	}

	/* fork and  execute the first command */
	pid1 = fork();
	if (pid1 == 0)
	{ /* The child process */
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[1]);
		_exec(argv2);
		exit(EXIT_SUCCESS);
	}
	else if (pid1 > 0)
	{	/* The parent process */
		pid2 = fork();
		if (pid2 == 0)
		{ /* The child process */
			dup2(pfd[1], STDOUT_FILENO);
			close(pfd[0]);
			/* execute the command */
			_exec(argv1);
			exit(EXIT_SUCCESS);
		}
		else if (pid2 > 0)
		{	/* The parent process */

			close(pfd[0]);
			close(pfd[1]);
			/* used waitpid to wait  for both child processes to finish */
			waitpid(pid1, &status, 0);
			waitpid(pid2, &status, 0);
		}
	}
}

/**
* pipeCheck - function to check whether the input string contains the
* pipe character.
* @argv: an array of strings to check.
* Return: 1 or 0
*/

int pipeCheck(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		if (_strcmp(argv[i], "|") == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
* cmd_before_pipe - This function handles commands before pipe the character.
* @argv: an array of strings.
* Return: pointer to pointer.
*/

char **cmd_before_pipe(char **argv)
{
	int i = 0;
	char **argv1 = malloc(sizeof(char *) * MAX_ARGV);

	while (argv[i] != NULL && _strcmp(argv[i], "|") != 0)
	{
		argv1[i] = argv[i];
		i++;
	}
	argv1[i] = NULL;
	return (argv1);
}

/**
* cmd_after_pipe - This function handles commands before pipe the character.
* @argv: an array of strings
* Return: pointer to pointer
*/

char **cmd_after_pipe(char **argv)
{
	char **argv2 = malloc(sizeof(char *) * MAX_ARGV);
	int i = 0, j = 0;

	while (argv[i] != NULL && _strcmp(argv[i], "|") != 0)
	{
		i++;
	}
	i++;
	while (argv[i] != NULL)
	{
		argv2[j] = argv[i];
		i++;
		j++;
	}
	argv2[j] = NULL;
	return (argv2);
}

/**
* handle_pipes - This function checks if there are alot of pipes (|) in the
* argument list by calling the pipeCheck function.
* @argv: an array of string.
* Return: void
*/

void handle_pipes(char **argv)
{
	int i = 0;
	char **argv1 = NULL, **argv2 = NULL;

	while (argv[i] != NULL)
	{
		if (_strcmp(argv[i], "|") == 0)
		{
			argv1 = malloc(sizeof(char *) * MAX_ARGV);
			argv2 = malloc(sizeof(char *) * MAX_ARGV);
			argv1 = cmd_before_pipe(argv);
			argv2 = cmd_after_pipe(argv);
			handle_pipe(argv1, argv2);
			free(argv1);
			free(argv2);
			i++;
		}

		else
			i++;
	}
}
