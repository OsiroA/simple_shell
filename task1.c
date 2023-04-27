#include "header.h"
int main()
{
    char *pointertoline = NULL;
    /*char *delimiter = " \t\n";*/
    size_t size = 0;
    ssize_t line = 0;
    pid_t process;
    char *args[] = {NULL};
    /**
    *void(argc);
    *void(**argv);
    */
    int child, status = 1;

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
        line = _strlen(pointertoline);
        if (line > 0 && pointertoline[line -1] == '\n')
        {
            pointertoline[line - 1] = '\0';
            process = fork();
            if (process == -1)
            {
                perror("Couldn't create child process");
            }
            else if (process == 0)
            {
                if (execve(pointertoline, args, NULL) == -1)
                {
                    perror("Couldn't execute command");
                    exit(EXIT_FAILURE);
                }
            }
            else
                waitpid(process, &child, 0);
        }
    }
    return (0);
}