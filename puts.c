#include "shell.h"
/**
 * _puts - This function prints a string to stdout
 * @str: a string of characters
 * Return: 0
 */

void _puts(char *str)
{
	int j = 0;

	while (*(str + j) != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	_putchar('\n');
}
