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

/* // Define the maximum number of arguments */
#define MAX_ARGS 1024
extern char **environ;


/**
*
*/
typedef struct liststr
{
	int num;

	char *str;

	struct liststr *next;
} list_t;
/* // Struct to hold information passed to functions*/
/**
*
*/
typedef struct info
{
	char *input; /*line*/
	list_t *env;
/*  // Add other members here if needed */
} info_t;
#define INFO_INIT { NULL, NULL}




/* // Function prototypes */
/*prompt.c*/
void prompt(void);
int is_input(void);
/*putchar.c*/
int _putchar(const char *c);
/*hsh*/
void hsh(info_t *info);
/*myfunc.c*/
void handle_hash(info_t *info);
int _myexit(info_t *info);
void free_args(char **args);
/*memoryfunc.c*/
char *_memset(char *s, char b, unsigned int n);

/* execve.c*/
void _execve(info_t *info);

/* execve1.c */
void _execve1(info_t *info);

/* stringfunc.c*/
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
/*stringfunc1.c*/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
/* _atoi */

/*spacestrtok.c */
int _spacestrtok(info_t *info, char **args);
/* haspath.c */
void _haspath(info_t *info, char **args);
/*getpath.c*/
void _getpath(info_t *info, char **args);
/*parentpid.c*/
void _parentpid(pid_t cpid);
/*getenv.c*/
char *_getenv(const char *name, char **envp);

/* // Function to check if a command is executable */
bool _isexec(char **args);

/* // Function to check if there is input available */
int is_input(void);

/* // Function to free memory allocated for arguments */
void free_args(char **args);


#endif /* MAIN_H */
