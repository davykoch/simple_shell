#include "main.h"
/**
<<<<<<< HEAD
 * _execve1 - calls the prog and
 * @line: string input by user
 * @linenumber: line number of line read
 * @av: argument vector
 * @envp: environment variable
 */
void _execve1(char *line, char **av, int linenumber)
=======
* custom_printf_env - custom prinft env function
* @env: environment parameter
*/
void custom_printf_env(char *env[])
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
	if (_strcmp(line, "env") == 0)
=======
	if (strcmp(line, "env") == 0)
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f
>>>>>>> refs/remotes/origin/master
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
<<<<<<< HEAD
			_putchar_str(*env);
			_putchar("\n");
=======
			/* _putchar(*env); */
			custom_printf_env(env);
>>>>>>> refs/remotes/origin/master
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
		_execve(line, av, linenumber);
=======
<<<<<<< HEAD
		_execve(info);
=======
		_execve(line, av, linenumber, envp);
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f
>>>>>>> refs/remotes/origin/master
	}

}
