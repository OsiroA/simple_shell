#include "shell.h"

/**
* my_getline - reads a line from a file descriptor
* @lineptr: pointer to a buffer to store the line
* @n: pointer to the size of the buffer
* @stream: pointer to the file stream to read from
* Return: On success, the number of bytes read, including the newline
*/

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t numbytes = 0;
	ssize_t c;
	char *newMem;

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 140;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = read(fileno(stream), &(*lineptr)[numbytes], 1)) > 0)
	{
		numbytes += c;
		if (numbytes == *n)
		{
			newMem = _realloc(*lineptr, *n, (*n) * 2);
			if (newMem == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = newMem;
			*n *= 2;
		}
		if ((*lineptr)[numbytes - 1] == '\n')
			break;
	}
	if (numbytes == 0 && c == EOF)
		return (-1);

	(*lineptr)[numbytes] = '\0';
	return (numbytes);
}
