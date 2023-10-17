#include "main.h"
/**
 * _execve - calls progs
 * @info: string input by user
 * Return: void
 */
void _execve(info_t *info)
{
	char *args[64]; /* check*/

	int arg_count; /*check*/

	pid_t cpid;

	arg_count = _spacestrtok(info, args);
	if (arg_count <= 0)
	{
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
	}
}
