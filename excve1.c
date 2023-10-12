#include "main.h"
/**
* _execve1 - calls the prog and
* @info: struct with userdata
*/
void _execve1(info_t *info)
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
	else if (input == '\0' || input == EOF)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		_execve(&info, av, linenumber);
	}
}
