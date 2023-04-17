#include "shell.h"

/**
* split_string - a function that splits a string into words.
* @str: string to split.
* @delim: delimiter to split string by.
* @readl: size of the (str) string.
* Return: Array of pointers to strings with each element being a word.
*/
char **split_string(char *str, char *delim, ssize_t readl)
{
	char **argv;
	char *copy, *token;
	int i, j, ntokens = 0;

	if (readl <= 1)
		return (NULL);
	copy = malloc(sizeof(char) * readl);
	if (copy == NULL)
		return (NULL);

	_strcpy(copy, str);
	token = _strtok(str, delim);
	/* determine how many tokens are there*/
	while (token != NULL)
	{	ntokens++;
		token = _strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (ntokens + 1));
	if (argv == NULL)
	{	free(copy);
		return (NULL);
	}
	/* Store each token in the argv array */
	token = _strtok(copy, delim);
	for (i = 0; token != NULL; i++)
	{	argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			free(copy);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(copy);
	return (argv);
}
