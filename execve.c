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


	if (_strcmp(line, "setenv") == 0)
	{
		if (!args[1] || args[2])
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
			return;
		}
		process_setenv(args[1], args[2]);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (!args[1])
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return;
		}
		process_unsetenv(args[1]);
	}

	if (arg_count > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			_myexit(args, av, linenumber);
		}

		args[arg_count] = NULL;
		_fork(args, line);
	}
	else
	{
		/* handle exit*/
		if (_strcmp(line, "exit") == 0)
		{
			/* free(line); */
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
	}
}



