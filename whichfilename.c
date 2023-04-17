#include "main.h"

char *_which(char *filename)
{
	char *getpath = getenv("PATH");
	char *address, *eachtoken;
	size_t filenamelength, tokenlength;
	
	if (getpath == NULL)
	{
		return (NULL);
	}
	filenamelength = _strlen(filename);
	address = malloc(sizeof(char) * (filenamelength + 256));
	if (address == NULL)
	{
		return (NULL);
	}

	tokenlength = _strlen(eachtoken);
	eachtoken = _strtok(getpath, ":");
	while (eachtoken != NULL)
	{
		/*create the path using puts since sprintf is not allowed */
		_puts(eachtoken);
		_putchar('/');
		_puts(filename);
		_puts('\0');

		if (access(address, F_OK) == 0)
		{
			return (address);
		}
		eachtoken = _strtok(NULL, ":");
	}
	free(address);
	return (NULL);
}
int main(int argc, char **av)
{
	char *filename, *address;
	int a;

	for (a = 1; a < argc; a++)
	{
		filename = av[a];
		address = _which(filename);

		if (address != NULL)
		{
			printf("%s\n", address);
			free(address);
		}
		else
		{
			printf("%s not found in PATH\n", filename);
		}
	}
	return (0);
}
