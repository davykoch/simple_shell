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
 * struct liststr - contains list of str
 * @num: the number of str
 * @str: string
 * @next: next node
 */
typedef struct liststr
{
	int num;

	char *str;

	struct liststr *next;
} list_t;
/**
 * struct info - holds all info
 * @input: what user writes
 * @env: env it runs in
 * @args:gotten from getline func
 * @err_num: error number
 * @e_status: exit status
 */
typedef struct info
{
	/*int from_pipe; */
	char *input; /*line*/
	list_t *env;
	char **args;
	int err_num;
	int e_status;
} info_t;
#define INFO_INIT {NULL, NULL, NULL, 0, 0}




/* // Function prototypes */
/*prompt.c*/
int prompt_display(void);
int is_input(void);
/*putchar.c*/
int _putchar(const char *c);
/*hsh*/
void hsh(info_t *info, int from_pipe);
/*myfunc.c*/
void handle_hash(info_t *info);
int _myexit(info_t *info);
void free_args(char **args);
/*memoryfunc.c*/
char *_memset(char *s, char b, unsigned int n);

/* execve.c*/
void _execve(info_t *info);

/* execve1.c */
void custom_printf_env(char *env[]);
void _execve1(info_t *info);

/* stringfunc.c*/
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _erratoi(char *s);
/*stringfunc1.c*/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
/* _atoi */

/*spacestrtok.c */
int _spacestrtok(info_t *info, char **args);
/* haspath.c */
void _haspath(char **args);
/*getpath.c*/
void _getpath(info_t *info, char **args);
/*parentpid.c*/
void _parentpid(pid_t cpid);
/*getenv.c*/
char *_getenv(char *path_token, char **args);

/* // Function to check if a command is executable */
bool _isexec(char **args);

/* // Function to check if there is input available */
int is_input(void);

/* // Function to free memory allocated for arguments */
void free_args(char **args);
<<<<<<< HEAD
=======
void _haspath(char **args, char **envp, char *line);

int _myexit(char **args);
void _fork(char **args, char *line, char **av, int linenumber, char **envp);

>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f


#endif /* MAIN_H */
