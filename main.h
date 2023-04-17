#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **split_string(char *str, char *delim, ssize_t readl);
int _putchar(char c);
#endif /* MAIN_H */
