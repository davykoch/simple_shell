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
#define MAX_ARGS 64
extern char **environ;

/* // Struct to hold information passed to functions*/
/**
*
*/
typedef struct info
{
	char *input; /*line*/

/*  // Add other members here if needed */
} info_t;

/**
*
*/
typedef struct liststr
{
	int num;

	char *str;

	struct liststr *next;
} list_t;



/* // Function prototypes */

/* // Function to execute a command */
void _execve(info_t *info, char **args, int linenumber, char **envp);

/* // Function to execute a command with specific arguments */
void _execve1(char **args, int linenumber, char **envp);

/* // String manipulation functions */
char *_strdup(const char *str);

char *_strcpy(char *dest, const char *src);

int _strcmp(const char *s1, const char *s2);

char *_sttypedef struct liststr
{
	int num;

	char *str;

	struct liststr *next;
} list_t;rcat(char *dest, const char *src);

int _strlen(const char *s);

/* // Function to tokenize a string */
int _tokenize(char *string, char *delim);

/* // Function to print a character */
int _putchar(const char c);

/* // Function to get an environment variable */
char *_getenv(const char *name, char **envp);

/* // Function to get the PATH variable and populate info structure */
void _getpath(info_t *info, char **args, char **av, int linenumber, char **envp);

/* // Function to check if a command is executable */
bool _isexec(char **args);

/* // Function to check if there is input available */
int is_input(void);

/* // Function to tokenize a string with specific arguments */
int _spacestrtok(info_t *info, char **args);

/* // Function to get the parent process ID */
void _parentpid(pid_t ppid);

/* // Function to free memory allocated for arguments */
void free_args(char **args);

/* // Function to check if a path exists */
void _haspath(info_t *info, char **args, char **envp);

#endif /* MAIN_H */
