#include "main.h"
/**
* _execve - calls progs
* @line:string input by user
* @av: argument vector
* @linenumber: line number of the line read
* Return: void
*/
void _execve(char *line, char **av, int linenumber)
{
	char *args[64]; /* check*/

	int arg_count = _spacestrtok(line, args);

	if (arg_count <= 0)
	{
		if (_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		/* free(line); */
		return;
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (!args[1] || args[2])
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
			/* free(line); */
			return;
		}
		process_setenv(args[1], args[2]);
		/* free(line); */
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (!args[1])
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			/* free(line); */
			return;
		}
		process_unsetenv(args[1]);
	}
		if (_strcmp(args[0], "exit") == 0)
		{
			_myexit(args, av, linenumber);
			/* free(line); */
		}
		args[arg_count] = NULL;
		_fork(args, line);
		/* free(line); */
}
