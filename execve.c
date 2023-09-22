#include "main.h"
/**
* _execve - calls progs
* @line:string input by user
* Return: void
*/
void _execve(char *line, char **av, int linenumber) /* check if return void or int*/
{
	int arg_count = 0;

	char *args[100]; /* check*/

	pid_t pid;
	char *delim = " ";

	/* token = int _tokenize(line, delim, &arg_count);*/
	char *token = strtok(line, delim); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = strdup(token); /* strdup to maintain original line*/
		token = strtok(NULL, delim);
	}
	if (arg_count > 0)
	{
		args[arg_count] = NULL;

		pid = fork(); /* child process*/
		/* where we use cmds entered */
		if (pid == -1)
		{
			perror("error -fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* sucessfull*/
		{
			/* This code runs in the child process */
			/*char **env = environ;*/

			if (access(args[0], X_OK) == 0)
			{

				int exve = execve(args[0], args, environ); /*NULL*/

				if (exve == -1)
				{
					perror("error -access");

					free(line);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				_getpath(line, args, av, linenumber);
			}
		}
		else
		{
			while (1)
			{
				wpid = waitpid(child_pid, &status, WUNTRACED);
				if (wpid == -1)
				{
					perror("waitpid");
					exit(EXIT_FAILURE);
				}

				if (WIFEXITED(status) || WIFSIGNALED(status))
				{
					break;
				}
			}
			/*parent pid waits for child*/
			/*wait(NULL);  Wait for the child to complete */
		}

		/**
		 * printf("%s", line);
		 * printf("$");
		 */
	}
}
