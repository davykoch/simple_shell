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
/*putchar.c*/
int _putchar(const char *c);
void _putchar_str(const char *s);

/*handlers.c*/
void handle_hash(char *line);

/*err_handlers.c*/
void _eputs(char *str);
int _eputchar(char c);
int _erratoi(char *str);


/*myexit.c*/
int _putint(int input, int fd);

void _execve(char *line, char **av, int linenumber);

void _execve1(char *line, char **av, int linenumber);

/*string functions*/
char *_strdup(const char *str);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

int _strlen(const char *s);

char *_getenv(char *path_token, char **args);

void _getpath(char *line, char **args, char **av, int linenumber);

bool _isexec(char **args);

int is_input(void);

int _spacestrtok(char *line, char **args);

void _parentpid(pid_t pid);
void free_args(char **args);
void _haspath(char **args, char *line);

int _myexit(char **args);
void _fork(char **args, char *line, char **av, int linenumber);



#endif /*MAIN_H*/
