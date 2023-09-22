#include "main.h"
/**
  * is_input - checks for interactive
  * Return: integer value
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

	(void) ac;
	(void) envp;
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
				perror("cannot get line"); /* check */
				free(line);
				exit(EXIT_FAILURE);
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		_execve1(line, av, linenumber);
	}
	free(line);
	return (0);
}
