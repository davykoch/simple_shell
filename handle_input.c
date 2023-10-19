#include "main.h"
/**
*
*
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
			/* free(line); */
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("cannot get line"); /* check */
			/* free(line); */
			exit(EXIT_FAILURE);
		}
	}
	if (reead == 0) /* End of File (Ctrl+D) */
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		/* free(input); */
		exit(EXIT_SUCCESS);
	}
	if (reead == '\0' || reead == EOF)
	{
		exit(EXIT_SUCCESS);
		/* free(input); */
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
