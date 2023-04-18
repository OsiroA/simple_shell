#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;

int _exec(char **args);
int _cd(char **args);
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
