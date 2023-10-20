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

	int index = 0;

	ssize_t reead;

	/* reead = _getline(&line, &line_size); */
	reead = read(STDIN_FILENO, line, MAX_ARGS);
	if (reead == -1)
	{
		exit(errno);
	}
	while (line[index])
	{ /* remove '\n' */
		if (line[index] == '\n')
			line[index] = '\0';
		index++;
	}
	if (reead == '\0' || reead == EOF)
		exit(EXIT_SUCCESS);
	if (reead == 0) /* End of File (Ctrl+D) */
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	/* handle_hash(line); */
}
