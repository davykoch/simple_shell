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

	pid = fork(); /* child process*/
	if (pid == -1)
	{
		perror("error -fork");
		/* free_args(args); */
		freeline(&line);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* sucessfull*/
	{
		char **args = _execve(line, av, linenumber);

		if (strchr(args[0], '/') != NULL)
		{
			_haspath(args);
			freeline(&line);
		}
		else
		{
			_getpath(args);
			free_args(args);
			freeline(&line);
		}
	}
	else
	{
		_parentpid(pid);
	}
}
