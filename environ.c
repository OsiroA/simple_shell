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

/**
* _setenv - This function uses the setenv builtin command to
* initialize a new environment variable or modify an existin one
* @value: The desired value
* Return: void
*/
void _setenv(const char *value)
{
	const char* variable;

	variable = "our_path";
	setenv(variable, value, 1);
}

/**
* _unsetenv - This function uses the unsetenv to unset a set environment
* @variable: the variable name passed into the setenv function
* Return: void
*/
void _unsetenv(const char* variable)
{
	unsetenv(variable);
}