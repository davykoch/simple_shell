#include "main.h"
/**
 * _execve - calls progs
 * @info: string input by user
 * Return: void
 */
 * _execve - calls progs
 * @info:string input by user
 * Return: void
 */
void _execve(info_t *info)
{
	char *args[64]; /* check*/
	int arg_count;	/*check*/
	pid_t cpid;

	arg_count = _spacestrtok(info, args);
	
	if (arg_count <= 0)
	{
		/* No arguments provided*/
		if (_strcmp(info->input, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		return;
	}
	if (_strcmp(info->args[0], "exit") == 0)
	{
		int exit_status = _myexit(info);

		exit(exit_status);
	}

	info->args[arg_count] = NULL;
	info->args[0] = info->input;
	cpid = fork(); /* child process*/
	if (cpid == -1)
	{
		perror("error -fork");
		/* free_args(args); */
		exit(EXIT_FAILURE);
	}
	else if (cpid == 0) /* sucessfull*/
	{
		if (_strchr(info->args[0], '/') != NULL)
		{					/*checks if input has directory*/
			_haspath(info); /*check*/
		args[arg_count] = NULL;
		args[0] = info->input;
		cpid = fork(); /* child process*/
		if (cpid == -1)
		{
			perror("error -fork");
			free_args(args);
			/* free(input); */
			exit(EXIT_FAILURE);
		}
		else if (cpid == 0) /* sucessfull*/
		{
			if (_strchr(args[0], '/') != NULL)
			{/*checks if input has directory*/
				_haspath(args);/*check*/
			}
			else
			{
				_getpath(info, args);/*execute*/

				free_args(args);
			}
		}
		else
		{
			_getpath(info); /*execute*/
		}
		/* free_args(args); */
		exit(EXIT_SUCCESS);
	}
	else
	{
		_parentpid(cpid);
		/* free_args(args); */
	}
}
