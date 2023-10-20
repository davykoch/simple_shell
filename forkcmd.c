#include "main.h"
/**
 * _fork - creates child process
 * @args: arguments
 * @line:string input by user
 * Return: void
 */
void _fork(char *line)
{
	pid_t pid;
	/* bool executable; */
	char *args[] = {NULL, NULL};
	int status;

	pid = fork(); /* child process*/
	if (pid == -1)
	{
		perror("error -fork");
		exit(errno);
	}
	else if (pid == 0) /* sucessfull*/
	{
		/* char **args = _execve(line, av, linenumber); */
		_spacestrtok(line, args);
		args[0] = line;
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		/* _parentpid(pid); */
	}
}
