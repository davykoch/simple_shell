#include "main.h"
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL; /* stores string from cmd line*/

	size_t len = 0;
	ssize_t read;
	/*bool from_pipe = false;*/

	/*printf("$");*/
	while (1)/*check*/
	{

		if (isatty(STDIN_FILENO) == 1)
		{
			/*from_pipe = true;*/
			write(STDOUT_FILENO, "$", 1);
		}
		read = getline(&line, &len, stdin);
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
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		/* handle exit*/
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Exit the shell*/
		}
		/*handle env*/
		if (strcmp(line, "env") == 0)
		{
			/* Handle the "env" command by printing the environment variables*/
			char **env = environ;
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}

		_execve(line);
	}
	return (0);
}
