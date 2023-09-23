#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>

extern char **environ;

void _execve(char *line, char **av, int linenumber, char **envp);

void _execve1(char *line, char **av, int linenumber, char **envp);

/*string functions*/
char *_strdup(const char *str);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

char *_getenv(char *path_token, char **args);

void _getpath(char *line, char **args, char **av, int linenumber, char **envp);

bool _isexec(char **args);

int is_input(void);

int _spacestrtok(char *line, char **args);

void _parentpid(pid_t pid);
void free_args(char **args);




#endif /*MAIN_H*/
