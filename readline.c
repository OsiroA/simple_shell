#include "shell.h"

/**
* _readline - reads input from user and stores it in a buffer
* @fp: file pointer to read input from
* Return: pointer to buffer containing user input
*/

char *_readline(FILE *fp)
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t nread = 0;

	/* read input from file pointer into buffer */
	nread = getline(&lineptr, &length, fp);
	if (nread == -1) /* if reading failed */
	{
		free(lineptr); /* free memory allocated for buffer */
		exit(0); /* exit program with success */
	}

	return (lineptr); /* return pointer to buffer */
}

/**
* split_string - This function tokenizes it into an array of strings.
* @str:  a pointer to the string that needs to be tokenized.
* Return: pointer to array of tokens or NULL.
*/

char **split_string(char *str)
{
	char **tokens = NULL;
	char *token = NULL;
	unsigned int ntokens = 0;

	if (str == NULL || DELIM == NULL)
		return (NULL);

	/* Allocate space for the array of tokens */
	tokens = malloc(sizeof(char *) * BUFSIZE);
	if (tokens == NULL)
		return (NULL);

	/* Tokenize the string */
	token = strtok(str, DELIM);
	while (token != NULL && ntokens < BUFSIZE - 1)
	{
		tokens[ntokens++] = token;
		token = strtok(NULL, DELIM);
	}
	tokens[ntokens] = NULL;

	return (tokens);
}
