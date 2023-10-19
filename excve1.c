#include "main.h"
/**
* _execve1 - calls the prog and
* @info: struct with userdata
*/
void _execve1(info_t *info)
{

	if (strcmp(line, "env") == 0)
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
			_putchar_str(*env);
			_putchar("\n");
			/* _putchar(*env); */
			custom_printf_env(env);
			env++;
		}
	}
	else if (_strcmp(info->input, "exit") == 0)
	{
		/* free(input); */
		exit(EXIT_SUCCESS); /* Exit the shell*/
	}
	else
	{
		_execve(line, av, linenumber);
	}
}
