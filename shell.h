#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


void help_cmd(void);
void exit_cmd(char **args);
void cd_cmd(char **args);
int pipeCheck(char **argv);
void handle_pipe(char **argv1, char **argv2);
char **cmd_before_pipe(char **argv);
void handle_pipes(char **argv);
char **cmd_after_pipe(char **argv);


extern char **environ;

#define MAX_ARGV 32
#define BUF 1024
int _atoi(char *s);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *enVar);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *find_command(char *cmd);
int _exec(char **args);
int element_counter(void);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **split_string(char *str, char *delim, ssize_t readl);
char *_which(char *filename);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strtok(char *ptrtostr, char *delimiter);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif /* SHELL_H */
