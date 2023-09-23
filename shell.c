#include "main.h"
/**
 *
 *
 */
void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
/**
 * is_input - checks for interactive
 * Return: integer value
 */
int is_input(void)
{

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * main - its the main shell
 * @ac: argument count
 * @av: argument vector
 * @envp: environment variable
 * Return: 0 on success
 */
int main(int ac, char **av, char **envp)
{

	size_t len = 0;
	ssize_t read;
	int from_pipe;

	int linenumber = 0;

	char *line = NULL; /* stores string from cmd line*/

	(void)ac;
	from_pipe = is_input();
	while (1) /*check*/
	{
		linenumber++;
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				if (from_pipe && isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				free(line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("cannot get line"); /* check */
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		_execve1(line, av, linenumber, envp);
	}
	free(line);
	return (0);
}
