#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define EMPTYPATH_ERR "No such file or directory\n"
#define MALLOC_ERR "Unable to allocate memory\n"
#define FORK_ERR "Unable to fork and create child process\n"
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"


/**
* struct built - linked list of builtin functions,
* @name: name of builtin
* @ptr: pointer to function
* Description: struct for builtin functions.
*/

typedef struct built
{
        char *name;
        int (*ptr)(void);
} built;



extern char **environ;

void prompt(void);
int num_builtinf(built builtinf[]);
char *_readline(FILE *fp);
void _puts(char *str);
void free_memory(char **tokens, char *valPath, char *lineptr, char *fullPath, int flag);
void free_doubleP(char **argv, unsigned int n);
char **split_string(char *str);
void get_error(int error);
char **envcpy(char **dst, char **src, unsigned int len);
char *find_exec(char *cmd, char *fullPath, char *path);
char *_getenv(const char *str);
int _exec(char *str, char **argv);
int env_cmd(void);
int exit_cmd(void);
int exe_builtinf(char **argv);
int _strcmp(char *src, char *value, unsigned int length);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif /* SHELL_H */
