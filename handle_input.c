#include "main.h"
/**
 * handle_input - handles input
 * @line:user input
 * @from_pipe: isatty
 * @reead: read
 * Return:0;
 */
void handle_input(char *line, int from_pipe, ssize_t reead)
{
	int i = 0;

	if (reead == -1)
	{
		if (feof(stdin))
		{
			if (from_pipe && isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("cannot get line"); /* check */
			exit(EXIT_FAILURE);
		}
	}
	if (reead == 0) /* End of File (Ctrl+D) */
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (reead == '\0' || reead == EOF)
	{
		exit(EXIT_SUCCESS);
	}
	line[reead] = '\0'; /* Null-terminate the buffer */
	for (i = reead - 1; i > 0 && (line[i] == '\n' || line[i] == '\r'); i--)
	{
		line[i] = '\0';
	}
	handle_hash(line);
	if (line[reead - 1] == '\n')
		line[reead - 1] = '\0';
	if (line[0] == '\0')
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
