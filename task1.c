#include "header.h"

int main(int argc  __attribute__((unused)), char **argv)
{
	char *lineP = NULL;
	char *token, *delimiter = " \t\n";
	size_t size = 0;
	ssize_t rline = 0;
	pid_t process;
	char *args[1024];
	char *command = argv[0];
	extern char **environ;
	int child, status = 1, i = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		rline = getline(&lineP, &size, stdin);
		if (rline == -1 || (rline == 0 && lineP[0] == '\0'))
		{
			free(lineP);
			exit(0);
		}
		if (lineP == NULL || lineP[0] == '\0' || lineP[0] == ' ' || lineP[0] == '\n')
			continue;
		rline = _strlen(lineP);
		if (rline > 0 && lineP[rline -1] == '\n')
			lineP[rline - 1] = '\0';
		process = fork();
		if (process == -1)
		{
			perror("Couldn't create child process");
		}
		else if (process == 0)
		{
			token = strtok(lineP, delimiter);
			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, delimiter);
			}
			args[i] = NULL;
			if (execve(args[0], args, environ) == -1)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(process, &child, 0);
	}
	free(lineP);
	return (0);
}
