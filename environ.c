#include "shell.h"

/**
* envcpy -  This function is used to create a copy of the environment variable.
* @dst: pointer to the copy of the environment variable
* @src: pointer to the original environment variable
* @len: length of the environment variable
* Return: double pointer to dst.
*/

char **envcpy(char **dst, char **src, unsigned int len)
{
	char *var;
	unsigned int var_len, i = 0;

	dst = malloc(sizeof(char *) * (len + 1));
	if (dst == NULL)
	{
		get_error(3);
		return (NULL);
	}
	while (i < len)
	{
		var = src[i];
		var_len = _strlen(var);
		dst[i] = malloc(sizeof(char) * (var_len + 1));
		if (dst[i] == NULL)
		{
			get_error(3);
			free_doubleP(dst, i);
			return (NULL);
		}
		_strcpy(dst[i], var);
		i++;
	}
	dst[i] = NULL;

	return (dst);
}

/**
* _getenv - This function retrieves the value of a given environment variable
* @str: Pointer to a string representing the name of the environment variable
* to get.
* Return: double pointer or NULL.
*/

char *_getenv(const char *str)
{
	int cmp;
	char **copy = NULL;
	char *path, *curr_env, *currVal;
	unsigned int path_len, env_len, len, i = 0;

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;
	copy = envcpy(copy, environ, env_len);

	len = _strlen((char *)str);
	while (copy[i])
	{
		curr_env = copy[i];
		cmp = _strncmp((char *)str, curr_env, len);
		if (cmp == 1)
		{
			currVal = strtok(curr_env, "=");
			currVal = strtok(NULL, "\n ");
			if (*currVal == '\0')
			{
				get_error(4);
				exit(1);
			}
			path_len = _strlen(currVal);
			path = malloc(sizeof(char) * path_len + 1);
			if (!path)
			{
				get_error(3);
				return (NULL);
			}
			path = _strcpy(path, currVal);
			free_doubleP(copy, env_len);
			return (path);
		}
		i++;
	}
	return (NULL);
}
