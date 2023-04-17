#include "main.h"

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
	int i, ntokens = 0;

	copy = malloc(sizeof(char) * readl);
	if (copy == NULL)
		return (NULL);

	_strcpy(copy, str);
	token = strtok(str, delim);
	/* determine how many tokens are there*/
	while (token != NULL)
	{
		ntokens++;
		token = strtok(NULL, delim);
	}
	ntokens++;
	argv = malloc(sizeof(char *) * ntokens);
	/* Store each token in the argv array */
	token = strtok(copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
		_puts(argv[i]);
	}
	argv[i] = NULL;
	free(copy);
	for (i = 0; i < ntokens; i++)
		free(argv[i]);

	free(argv);

	return (argv);
}
