#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, unsigned int n);
int _strcmp(char *src, char *value, unsigned int length);
int _exec(char *fullPath, char **argv);
void get_error(int error);
void free_memory(char **tokens, char *vaPa, char *lptr, char *fulPa, int flag);
void free_doubleP(char **argv, unsigned int n);
char *_strcpy(char *dest, char *src);

#endif
