#include "main.h"
/**
* custom_printf_env - custom prinft env function
* @env: environment parameter
*/
void custom_printf_env(char *env[])
{
<<<<<<< HEAD
	int i = 0;

	while (env[i] != NULL)
	{
		size_t len = 0;

		while (env[i][len] != '\0')
		{
			len++;
		}
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
* _execve1 - calls the prog and
* @info: struct with userdata
*/
void _execve1(info_t *info)
{

	/*handle env*/
	if (_strcmp(info->input, "env") == 0)
=======
	/*handle env*/
	if (strcmp(line, "env") == 0)
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
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
<<<<<<< HEAD
		_execve(info);
=======
		_execve(line, av, linenumber, envp);
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f
	}

}
