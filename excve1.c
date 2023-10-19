#include "main.h"
/**
 * _execve1 - calls the prog and
 * @line: string input by user
 * @linenumber: line number of line read
 * @av: argument vector
 * @envp: environment variable
 */
void _execve1(char *line, char **av, int linenumber)
{
	/*handle env*/
	if (_strcmp(line, "env") == 0)
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
			_putchar_str(*env);
			_putchar("\n");
			env++;
		}
	}
	else
	{
		_execve(line, av, linenumber);
	}
}
