#include "main.h"

/**
* main - its the main shell
* Return: 0 on success
*/
int main(void)
{
<<<<<<< HEAD
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
	int linenumber;
	size_t len = 0;
	ssize_t read;
	int from_pipe;

	char *line = NULL; /* stores string from cmd line*/

	(void)ac;
=======
	info_t info[] = {INFO_INIT};
	int from_pipe;

>>>>>>> refs/remotes/origin/master
	from_pipe = is_input();

	while (1)
	{
		if (from_pipe && isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$- ", 2);
			fflush(stdout);
		}
<<<<<<< HEAD
		handle_hash(line);
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		_execve1(line, av, linenumber);
=======
		hsh(info, from_pipe);
		_execve1(info);
		/* return (0); */
		free(info->input);
>>>>>>> refs/remotes/origin/master
	}
}
