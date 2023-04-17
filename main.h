#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **split_string(char *str, char *delim, ssize_t readl);
char *_which(char *filename);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strtok(char *ptrtostr, char delimiter);

#endif /* MAIN_H */
