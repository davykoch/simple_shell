#include "main.h"
/**
 *
 *
 */
int is_input(void)
{

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		/*write(STDOUT_FILENO, "Running interactively.\n", 23);*/
		return (1);
	}
	else
	{
		/*write(STDOUT_FILENO, "Running non-interactively.\n", 27);*/
		return (0);
	}
}
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(int ac, char **av, char **envp)
{

	size_t len = 0;
	ssize_t read;
	int from_pipe;
	/*	bool is_input;*/
	char *line = NULL; /* stores string from cmd line*/
	(void)ac;
	(void)av;

	/*bool from_pipe = false;*/

	from_pipe = is_input();
	/*printf("$");*/
	while (1) /*check*/
	{

		if (from_pipe)
		{
			/*from_pipe = true;*/
			write(STDOUT_FILENO, "$ ", 2);
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
		else if (strcmp(line, "env") == 0)
		{
			/* Handle the "env" command by printing the environment variables*/
			char **env = envp;
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			continue; /*check*/
		}
		else
		{

			_execve(line, envp);
		}
	}
	free(line);
	return (0);
}
