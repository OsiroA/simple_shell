#include "shell.h"

/**
* _getenv - retrieves the value of an environmental variable (PATH).
* @enVar: environmental variable to retrieve.
* Return: a pointer to a string that represents the value of
* the environment variable or NULL.
*/

char *_getenv(const char *enVar)
{
	char **env = environ;
	char *keyVal, *key, *value, *result;

	if (!env)
		return (NULL);

	while (*env)
	{
		keyVal = _strdup(*env);
		key = _strtok(keyVal, "=");
		value = _strtok(NULL, "=");

		if (_strcmp(key, enVar) == 0)
		{
			result = _strdup(value);
			free(keyVal);
			return (result);
		}
		free(keyVal);
		env++;
	}

	return (NULL);
}
