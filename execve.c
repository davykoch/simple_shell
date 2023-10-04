#include "main.h"
/**
 * _execve - calls progs
 * @line:string input by user
 * @av: argument vector
 * @linenumber: line number of the line read
 * @envp: environment variable
 * Return: void
 */
void _execve(char *line, char **av, int linenumber, char **envp, info_t info)
{
	char *args[64]; /* check*/

	pid_t pid;

	int arg_count = _spacestrtok(line, args);

	if (arg_count > 0)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			int exit_status = my_exit(info);
			exit(exit_status);
		}

		args[arg_count] = NULL;
		pid = fork(); /* child process*/
		if (pid == -1)
		{
			perror("error -fork");
			free_args(args);
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* sucessfull*/
		{
			if (strchr(args[0], '/') != NULL)
			{
				_haspath(args, envp, line);
			}
			else
			{
				_getpath(line, args, av, linenumber, envp);
				free_args(args);
			}
		}
		else
		{
			_parentpid(pid);
		}
	}
	else
	{
		/* handle exit*/
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
	}
}
