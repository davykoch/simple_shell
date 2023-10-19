#include "main.h"
/**
 * _fork - creates child process
 * @args: arguments
 * @line:string input by user
 * Return: void
 */
void _fork(char **args, char *line)
{
	pid_t pid;

	pid = fork(); /* child process*/
	if (pid == -1)
	{
		perror("error -fork");
		free_args(args);
		free(line);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* sucessfull*/
	{
		if (strchr(args[0], '/') != NULL)
		{
			_haspath(args);
		}
		else
		{
			_getpath(args);
			free_args(args);
		}
	}
	else
	{
		_parentpid(pid);
	}
}
