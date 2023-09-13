#include "main.h"
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL; /* stores data from cmd line*/

	size_t len = 0;
	ssize_t read;
	int arg_count = 0;
	char *args[100]; /* do we use malloc*/
	pid_t pid;

	printf("$");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (read == 0) /* handles EOF - ctrl-d */
		{
			break;
		}
		if (read == -1)
		{
			perror("cannot get line"); /* check */
			free(line);
			exit(EXIT_FAILURE);
		}
		/* Remove the newline character if present*/
		if (read[line - 1] == '\n')
		{
			read[line - 1] = '\0';
		}

/* strdup to maintain original line*/
		char *token = strtok(line, " "); /*separate cmds singular*/

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		if (arg_count > 0)
		{
			pid = fork();
			/* where we use cmds entered */
			if (pid == -1) 
			{
                perror("fork");
				free(line);
                exit(EXIT_FAILURE);
            } 
			else if (pid == 0)/* sucessfull*/
			{
                /* This code runs in the child process */
				/* execve*/     

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
		free(line);

		return (0);
	}
}
