#include "main.h"
/**
 * free_args - free args
 * @args: arguments to be freed
 * Return: void
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
int main(int ac, char **av)
{
	int linenumber = 0;

	/* size_t len = 0; */

	int from_pipe;

	/* char *line = NULL;  */ /* stores string from cmd line*/
	char line[MAX_ARGS];

	(void)ac;
	from_pipe = is_input();
	while (1) /*check*/
	{
		linenumber++;
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$-", 2);
		/* reead = getline(&line, &len, stdin); */
		handle_input(line, from_pipe);
		if (!biultin(line))
		{
				_fork(line, av, linenumber);
		}
		/* free(line); */
	}
	/* free(line); */
	return (0);
}
