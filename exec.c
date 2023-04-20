#include "shell.h"

/**
* _exec - This function executes a function,
* checks for builtins and launches the process
* @args: arguments
* Return: 1 if success
*/
int _exec(char **args)
{
	pid_t childprocess;
	int a;

	childprocess = fork();

	/* error handling for if the execve fails*/
	if (childprocess == 0)
	{
		execve(args[0], args, environ);
		perror("./shell");
		exit(1);
	}
	/* telling the parent process to wait for the child process*/
	else if (childprocess > 0)
	{
		wait(&a);
		if (WIFEXITED(a))
		{
			return (1);
		}
		else
		{
			perror("Child process terminated abnormally");
			return (-1);
		}
	}
	/* error handling for if forking fails*/
	else
	{
		perror("Couldn't fork");
		return (-1);
	}
	return (1);
}



/**
*_cd - this function changes the directory 
* @args: argument passed
* Return: 0
*/

int _cd(char **args)
{
    if (args[1] == NULL)
    {
        perror("Directory name to move into not given");
    }
    else if (chdir(args[1]) == 0)
    {
        return (0);
    }
    else
    {
        perror("Could not change into the specified directory");
    }
    return (0);
}

/**
* my_exit - this function is a builtin function to exit the shell
* @args: the string passed into the function
*Return: void
*/
int my_exit(char **args)
{
	exit(98);
	return (0);
}

/**
* _help - This function shows the lisrt of available builtins when called
* @args: the string to be passed in
* Return: 0 if success
*/
int _help(char **args)
{
	char *help;

	help =
		"The commands below can be used in our shell:\n"
		" exit: This is used to exit the shell;\n"
		" help: This prints this particular manual you are reading\n"
		" cd: This changes the current working directory to a specified one\n";
	
	_puts("help");
}

/**
* our_builtinfunctions - This is a struct containing the association
* between a command name and the function it handles
*/
typedef struct
{
	char *arg;
	int (*my_function)(char **args);
} functions_builtin;

functions_builtin functions[3] = {
	[0] = {"exit", my_exit},
	[1] = {"help", _help},
	[2] = {"cd", _cd}
};

/**
* functions[0].arg = "exit";
* functions[0].my_function = my_exit;
* functions[1].arg = "help";
* functions[1].my_function = _help;
* functions[2].arg = "cd";
* functions[2].my_function = _cd;
*/

/**
* element_counter - Counts the number of elements in the builtin
* Return: number of elements
*/

int element_counter(void)
{
	return (sizeof(functions) / sizeof(functions_builtin));
}
