#include "main.h"
/**
 * _execve1 - calls the prog and
 * @line: string input by user
 * @linenumber: line number of line read
 * @av: argument vector
 * @envp: environment variable
 */
void _execve1(info_t *p_info, char **av, int linenumber, char **envp)
{
	
	/*handle env*/
	if (strcmp(p_info->input, "env") == 0)
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
		_execve(av, linenumber, envp);
	}
}
