#include "main.h"
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL; /* stores string from cmd line*/

	size_t len = 0;
	ssize_t read;
	bool from_pipe = false;
	
	write(STDOUT_FILENO, '$', 1);/*printf("$");*/
	while ((read = getline(&line, &len, stdin)) != -1 && !from_pipe) /*check*/
	{
		if (issaty(STDIN_FILENO) == 0)
		{
			from_pipe = true;
		}
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
		if (read[line - 1] == '\n')
		{
			read[line - 1] = '\0';
		}
		_execve(line);
		free(line);

		return (0);
	}
}
