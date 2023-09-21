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
			/**
			 *  execve
			 *_path();
			 */
			if (access(args[0], X_OK) == 0)
			{

				int exve = execve(args[0], args, NULL);

				if (exve == -1)
				{
					perror("error -execve");
					free(line);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				char *path = getenv("PATH");
				char *path_token = strtok(path, ":");

				while (path_token != NULL)
				{
					char *full_path = _getenv(path_token, args);

					if (access(full_path, X_OK) == 0)
					{
						int exve = execve(full_path, args, NULL);

						if (exve == -1)
						{
							perror("error -execve");
							free(line);
							free(full_path);
							exit(EXIT_FAILURE);
						}
					}
					free(full_path);
					path_token = strtok(NULL, ":");
				}
				/*/ If we reach here, the command was not found in PATH*/
				/*fprintf(stderr, "Command not found: %s\n", args[0]);*/
				perror("command not found");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*parent pid waits for child*/
			wait(NULL); /* Wait for the child to complete */
		}

		/**
		 * printf("%s", line);
		 * printf("$");
		 */
	}
}
