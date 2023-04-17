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
