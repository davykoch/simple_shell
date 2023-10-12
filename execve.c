#include "main.h"
/**
 * _execve - calls progs
 * @p_info:string input by user
 * @av: argument vector
 * @linenumber: line number of the line read
 * @envp: environment variable
 * Return: void
 */
void _execve(info_t *info, char **av, int linenumber, char **envp)
{
	char *args[] = {NULL, NULL} /* check*/

	pid_t cpid;

	int arg_count = _spacestrtok(info, args);

	if (arg_count > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			int exit_status = my_exit(info);

			exit(exit_status);
		}

		args[arg_count] = NULL;
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
			if (strchr(args[0], '/') != NULL)
			{
				_haspath(args, envp, p_info);
			}
			else
			{
				_getpath(p_info, args, av, linenumber, envp);
				free_args(args);
			}
		}
		else
		{
			wait(&(info->status));
			if (WIFEXITED(info->status))
			{
				info->status = WEXITSTATUS(info->status);
				if (info->status == 126)
					print_error(info, "Permission denied\n");
			}
		}
	}
	else
	{
		/* handle exit*/
		if (strcmp(p_info->input, "exit") == 0)
		{
			/* free(input); */
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
	}
}
