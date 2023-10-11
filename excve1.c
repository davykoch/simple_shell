#include "main.h"
/**
 * _execve1 - calls the prog and
 * @line: string input by user
 * @linenumber: line number of line read
 * @av: argument vector
 * @envp: environment variable
 */
void _execve1(info_t *info, char **av, int linenumber, char **envp)
{
	
	/*handle env*/
	if (_strcmp(info->input, "env") == 0)
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
			_putchar(env);
			env++;
		}
	}
	else
	{
		_execve(&info, av, linenumber, envp);
	}
}
