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
int main(int ac, char **av, char **envp)
{
	/* info_t *p_info;-pointer */
	info_t info[] = {INFO_INIT};
	int from_pipe;

	/**
	 *  p_info = malloc(sizeof(info_t));
	 *	if (p_info == NULL)
	 *	return (NULL);
	 */

	int linenumber = 0;

	char *input = NULL; /* stores string from cmd line*/

	/* (void)ac; */
	from_pipe = is_input();

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd; /*check*/
	}
	while (1) /*check*/
	{
		prompt();
		hsh(&info);
		_execve1(&info);
		return (0);
	}
}
