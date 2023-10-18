#include "main.h"
/**
* _execve - calls progs
* @line:string input by user
* @av: argument vector
* @linenumber: line number of the line read
* @envp: environment variable
* Return: void
*/
void _execve(char *line, char **av, int linenumber)
{
	char *args[64]; /* check*/

	int arg_count = _spacestrtok(line, args);

	if (arg_count > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			int exit_status;

			exit_status = _myexit(args);
			exit(exit_status);
		}

		args[arg_count] = NULL;
		_fork(args, line, av, linenumber);
	}
	else
	{
		/* handle exit*/
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
	}
}
