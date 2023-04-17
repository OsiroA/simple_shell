#include "main.h"

/**
* my_getline - reads a line from a file descriptor
* @lineptr: pointer to a buffer to store the line being read.
* @n: pointer to the size of the buffer.
* @stream: pointer to the file stream to read from
* Return: On success, the number of bytes read, including the newline.
* On failure, return -1.
*/

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t num_bytes = 0;
	ssize_t c;
	char *tmp;

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = read(fileno(stream), &(*lineptr)[num_bytes], 1)) > 0)
	{
		num_bytes += c;
		if (num_bytes == *n)
		{
			tmp = _realloc(*lineptr, *n * 2);
			if (tmp == NULL)
			{
				free(lineptr);
				return (-1);
			}
			*lineptr = tmp;
			*n *= 2;
		}
	}
	if (num_bytes == 0 && c == EOF)
		return (-1);

	(*lineptr)[num_bytes] = '\0';
	return (num_bytes);
}
