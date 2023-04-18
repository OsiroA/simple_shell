#include "shell.h"
int main()
{
    int result;

    // Prepare the arguments to be passed to our_exec()
    char *args[] = {"/bin/ls", "-l", NULL}; // Example: execute "ls -l" command

    // Call our_exec() with the arguments
    result = _exec(args);

    // Check the return value of our_exec()
    if (result == 1)
    {
        printf("Command executed successfully\n");
    }
    else if (result == -1)
    {
        printf("Failed to execute command\n");
    }

    return 0;
}