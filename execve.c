#include "main.h"
/**
<<<<<<< HEAD
 * _execve - calls progs
 * @info: string input by user
 * Return: void
 */
void _execve(info_t *info)
{
	char *args[64]; /* check*/

	int arg_count; /*check*/

	pid_t cpid;
=======
* _execve - calls progs
* @line:string input by user
* @av: argument vector
* @linenumber: line number of the line read
* @envp: environment variable
* Return: void
*/
void _execve(char *line, char **av, int linenumber, char **envp)
{
	char *args[64]; /* check*/

	int arg_count = _spacestrtok(line, args);
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f

	arg_count = _spacestrtok(info, args);
	if (arg_count <= 0)
	{
<<<<<<< HEAD
		if (_strcmp(info->input, "exit") == 0)
			exit(EXIT_SUCCESS);
		return;
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		int exit_status = _myexit(info);

		exit(exit_status);
	}
	args[arg_count] = NULL;
	cpid = fork(); /* child process*/
	if (cpid == -1)
	{
		perror("error -fork");
		exit(EXIT_FAILURE);
	}
	else if (cpid == 0) /* sucessfull*/
	{
		if (_strchr(args[0], '/') != NULL)
			_haspath(args); /*check*/
		else
			_getpath(info, args); /*execute*/
		exit(EXIT_SUCCESS);
	}
	else
	{
		_parentpid(cpid);
		/* free_args(args); */
=======
		if (strcmp(args[0], "exit") == 0)
		{
			int exit_status;

			exit_status = _myexit(args);
			exit(exit_status);
		}

		args[arg_count] = NULL;
		_fork(args, line, av, linenumber, envp);
	}
	else
	{
		/* handle exit*/
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
>>>>>>> 90b56def3e7656cf4d410a130b7191c83f2aff4f
	}
}
