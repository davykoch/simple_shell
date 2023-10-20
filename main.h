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
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define MAX_ARGS 1024
#define MAX_LINE 1023

/*getline*/
ssize_t _getline(char **line, size_t *line_size);
/* bool is_delim(char c, char *delim); */
int is_delim(char c, char *delim);

/*putchar.c*/
int _putchar(char c);
void _putchar_str(const char *s);

/*handlers.c*/
void handle_hash(char *line);

/*handle_input.c*/
void handle_input(char *line, int from_pipe);
void freeline(char **line);
/*err_handlers.c*/
void _eputs(char *str);
int _eputchar(char c);
int _erratoi(char *str);
/* tokenizer.c */
char **strtow(char *, char *);
char **strtow_2(char *, char);

/*myexit.c*/
int _putint(int input, int fd);
int _myexit(char **args, char **av, int linenumber);
void _perror(int linenumber, char *estr, char **av, char **args);

char **_execve(char *line, char **av, int linenumber);

/* biultin.c*/
int biultin(char *line);
/*string functions*/
char *_strdup(const char *str);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

int _strlen(const char *s);

char *_getenv(char *path_token, char **args);

/*get path.c*/
void _getpath(char **args);

bool _isexec(char **args);

int is_input(void);
/*handle_env.c*/
int process_setenv(char *variable_name, char *variable_value);
int process_unsetenv(char *variable_name);

int _spacestrtok(char *line, char **args);

void _parentpid(pid_t pid);
void free_args(char **args);
void _haspath(char **args);


void _fork(char *line, char **av, int linenumber);



#endif /*MAIN_H*/
