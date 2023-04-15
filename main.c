#include "shell.h"
/**
* main - entry point
* Return: 0 if success
*/
int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t a;

	while(1)
	{
		write(STDOUT_FILENO, "Shell$  ", 9);
		a = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			perror("no input found\n");
			return (-1);
		}
	}
	return (0);
}
