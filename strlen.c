#include "shell.h"

/**
 * _strlen - This function returns the length of a string
 * @s: a character
 * Return: 0
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

/**
* _strcpy - copy the string pointed to by src to dest
* @dest: char to check
* @src: char to check
* Return: 0 (success)
*/

char *_strcpy(char *dest, char *src)
{
	int p;

	for (p = 0; src[p] != '\0'; p++)
		dest[p] = src[p];
	dest[p] = '\0';
	return (dest);
}

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
* _strcmp - compare 2 string
* @s1:string 1
* @s2:string 2
* Return: int
*/

int _strcmp(const char *s1, const char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
