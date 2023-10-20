#include "main.h"
/**
 * 
 * 
*/
void freeline(char **line)
{
	if (line != NULL)
			{
				free(line);
			}
}
/**
 * handle_input - handles input
 * @line:user input
 * @from_pipe: isatty
 * @reead: read
 * Return:0;
 */
void handle_input(char *line, int from_pipe)
{
	/* int i = 0; */
	int k = 0;
	ssize_t reead;
	size_t line_size = 128;

	reead = _getline(&line, &line_size);
	if (reead == -1)
	{
		if (feof(stdin))
		{
			if (from_pipe && isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			freeline(&line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("cannot get line"); /* check */
			freeline(&line);
			exit(EXIT_FAILURE);
		}
	}
	while (line[k])
	{ /* remove '\n' */
		if (line[k] == '\n')
			line[k] = '\0';
		k++;
	}

	/* line[reead] = '\0';  */ /* Null-terminate the buffer */
	/**
	 * for (i = reead - 1; i > 0 && (line[i] == '\n' || line[i] == '\r'); i--)
	 *{
	 *line[i] = '\0';
	 *}
	 */
	if (reead == '\0' || reead == EOF)
	{
		freeline(&line);
		exit(EXIT_SUCCESS);
	}

	if (reead == 0) /* End of File (Ctrl+D) */
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		freeline(&line);
		exit(EXIT_SUCCESS);
	}
	handle_hash(line);

	/**
	 * if (line[0] == '\0')
	 *{
	 *if (isatty(STDIN_FILENO))
	 *write(STDOUT_FILENO, "\n", 1);
	 * free(line) *;
	 *exit(EXIT_SUCCESS);
	 *}
	 */
}
