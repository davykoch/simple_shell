#include "main.h"
/**
 * _fork - creates child process
 * @args: arguments
 * @line:string input by user
 * Return: void
 */
void _fork(char *line, char **av, int linenumber)
{
	pid_t pid;
	/* bool executable; */
	char *args[] = {NULL, NULL};

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
		if (_strcmp(args[0], "exit") == 0)
			_myexit(args, av, linenumber);

		if (strchr(args[0], '/') != NULL)
		{
			_haspath(args);
		}
		else
		{
			_getpath(args);
		}
	}
	else
	{
		_parentpid(pid);
	}
}
