#include "header.h"

/**
* main - Entry point of the program.
* @argc: argument count
* @argv: argument vector (an array of strings)
* Return: 0 if SUCCESS and -1 if FAILURE
*/

int main(int argc  __attribute__((unused)), char **argv)
{
	char *lineP = NULL, *token, *delimiter = " \t\n";
	size_t size = 0;
	ssize_t rline = 0;
	pid_t process;
	char *args[1024], *command = argv[0];
	int child, status = 1, i = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		rline = getline(&lineP, &size, stdin);
		if (rline == -1 || (rline == 0 && lineP[0] == '\0'))
		{	free(lineP);
			exit(0);
		}
		if (lineP == NULL || lineP[0] == '\0' || lineP[0] == ' ' || lineP[0] == '\n')
			continue;
		rline = _strlen(lineP);
		if (rline > 0 && lineP[rline - 1] == '\n')
			lineP[rline - 1] = '\0';
		process = fork();
		if (process == 0)
		{
			token = strtok(lineP, delimiter);
			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, delimiter);
			}
			args[i] = NULL;
			if (execve(args[0], args, environ) == -1)
			{	perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(process, &child, 0);
	}
	free(lineP);
	return (0);
}
