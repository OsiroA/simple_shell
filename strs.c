#include "shell.h"

/**
* _strcat - concat 2 strings
* @dest: char
* @src: char
* Return: char
*/

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
* _strdup -  Returns a pointer to a newly allocated space in memory
* @str: string
* Return: NULL or a char pointer
*/

char *_strdup(char *str)
{
	char *ptr;
	int n = 0, i;

	if (str == 0)
		return (NULL);

	while (str[n] != '\0')
		n++;

	ptr = (char *)malloc((n * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		ptr[i] = str[i];
	}
	ptr[n] = '\0';

	return (ptr);
}

/**
* _strlen - return the length of a string
* @s: char to check
* Return: 0 (success)
*/

int _strlen(char *s)
{
	int a = 0;

	for (; *s++;)
		a++;

	return (a);
}

/**
* _strncmp - compares two strings
* @s1: the first string to compare
* @s2: the second string to compare
* @n: the number of characters to compare
* Return: 1 or -1
*/

int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}

	return (1);
}

/**
* _strcmp - compares two strings.
* @src: string supplied by user
* @value: string to compare against
* @length: length of src
* Return: 1 if strings are equal, -1 if they are not
*/
int _strcmp(char *src, char *value, unsigned int length)
{
	unsigned int val_length;
	unsigned int i;

	val_length = _strlen(value);
	if (val_length != length)
		return (-1);

	i = 0;
	while (src[i] != '\0' && value[i] != '\0')
	{
		if (src[i] != value[i])
		return (1);
		i++;
	}
	return (0);
}
