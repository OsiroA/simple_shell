#include "shell.h"

/**
* exe_builtinf - This function executes the built in functions
* @argv: a pointer to pointer
* Return: an integer value
*/

int exe_builtinf(char **argv)
{
        int status;
        unsigned int len, num, i;

        built builtinf[] = {
                {"exit", exit_cmd},
                {"env", env_cmd},
                {NULL, NULL}
        };

        if (argv[0] == NULL)
                return (1);

        len = _strlen(argv[0]);

        num = num_builtinf(builtinf);
        for (i = 0; i < num; i++)
        {
                if (_strcmp(argv[0], builtinf[i].name, len) == 0)
                {
                  status = (builtinf[i].ptr)();
                  return (status);
                }
        }
        return (1);
}

/**
* num_builtinf - checks number built-in functions
* @builtin: the builtin to be counted
* Return: number of built-in functions
*/

int num_builtinf(built builtinf[])
{
        unsigned int i = 0;

        while (builtinf[i].name != NULL)
                i++;

        return (i);
}

/**
*exit_cmd - exits the shell
*Return: void
*/

int exit_cmd(void)
{
                return (-1);
}


/**
*env_cmd - prints the environment
*Return: void
*/

int env_cmd(void)
{
        unsigned int i = 0;
	char **env = environ;

        while (env[i] != NULL)
        {
                write(STDOUT_FILENO, env[i], _strlen(env[i]));
                write(STDOUT_FILENO, "\n", 1);
                i++;
        }
        return (0);
}
