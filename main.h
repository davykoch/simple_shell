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

void _execve(info_t *, char **, int , char **);

void _execve1(char **, int , char **);

/*string functions*/
char *_strdup(const char *str);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

int _strlen(char *s);
/* myfunc */
int _tokenize(char *string, char *delim);






int _putchar(const char );
char *_getenv(char *, char **);

void _getpath(info_t *, char **, char **, int, char **);

bool _isexec(char **);

int is_input(void);

int _spacestrtok(info_t *, char **);

void _parentpid(pid_t);
void free_args(char **);
void _haspath(info_t *, char **, char **);

#define MAX_ARGS 64;
#define INFO_INIT \
{NULL}
/**
* struct info - infor to be sent to all functions
*
*/
typedef struct info
{
	char *input;	

} info_t;


/**
* builtin - checks biult in func
*
*/
typedef struct builtin
{
	char *type;

	int (*func)(info_t *);
} builtin_table;


#endif /*MAIN_H*/
