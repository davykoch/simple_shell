#include "main.h"
/**
* _execve - calls progs
* @p_info:string input by user
* Return: void
*/
void _execve(info_t *info)
{
	char *args[] = {NULL, NULL}; /* check*/
	int arg_count;/*check*/
	pid_t cpid;

	arg_count = _spacestrtok(info, args);

	if (arg_count > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			int exit_status = _myexit(info);

			exit(exit_status);
		}

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
			_parentpid(cpid);
		}

	}
	else
	{
		/* handle exit*/
		if (_strcmp(info->input, "exit") == 0)
		{
			/* free(input); */
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
	}
}
