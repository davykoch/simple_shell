#include "main.h"
/**
 * _execve - calls progs
 * @line:string input by user
 * Return: void
 */
void _execve(char *line) /* check if return void or int*/
{
	int arg_count = 0;
	char *args[100]; /* check*/
	pid_t pid;

	char *token = strtok(line, " "); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = _strdup(token); /* strdup to maintain original line*/
		token = strtok(NULL, " ");
	}
	if (arg_count > 0)
	{
		args[arg_count] = NULL;

		pid = fork(); /* child process*/
		/* where we use cmds entered */
		if (pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* sucessfull*/
		{
			/* This code runs in the child process */
			/* execve*/
			_path();

			int exve = execve(args[0], args, NULL);

			if (exve == -1)
			{
				perror("execve");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*parent pid waits for child*/
			wait(NULL); /* Wait for the child to complete */
		}

		/*printf("%s", line);*/
		printf("$");
	}
}