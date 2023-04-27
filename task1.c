#include "header.h"
int main()
{
    char *pointertoline = NULL;
    /*char *delimiter = " \t\n";*/
    size_t size = 0;
    ssize_t line = 0;
    /**
    *void(argc);
    *void(**argv);
    */
    int status = 1;

    while (status)
    {
        write(STDOUT_FILENO, "$ ", 2);
        line = getline(&pointertoline, &size, stdin);
        if (line == -1)
        {
            perror("exit");
            free(pointertoline);
            return (-1);
        }
    }
    return (0);
}