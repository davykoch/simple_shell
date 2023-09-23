#include "main.h"
/**
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

	pid_t pid;

	int arg_count = _spacestrtok(line, args);

	if (arg_count > 0)
	{
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
				if (access(args[0], X_OK) == 0)
				{

					if ((execve(args[0], args, envp)) == -1)
					{
						perror("error -access");
						free_args(args);
						free(line);
						exit(EXIT_FAILURE);
					}
				}
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
}
