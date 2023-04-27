#include "header.h"

int main(int argc  __attribute__((unused)), char **argv)
{
    char *pointertoline = NULL;
    char *token, *delimiter = " \t\n";
    size_t size = 0;
    ssize_t line = 0;
    pid_t process;
    char *args[1024];
    char *command = argv[0];
    extern char **environ;

    int child, status = 1, i = 0;

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
                token = strtok(pointertoline, delimiter);
                while (token != NULL)
                {
                    args[i++] = token;
                    token = strtok(NULL, delimiter);
                }
                args[i] = NULL;
                if (execve(args[0], args, environ) == -1)
                {
                    perror(command);
                    exit(EXIT_FAILURE);
                }
            }
            else
                waitpid(process, &child, 0);
        }
    }
    free(pointertoline);
    return (0);
}