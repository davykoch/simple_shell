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
	/*bool from_pipe = false;*/

	write(STDOUT_FILENO, "$", 1);									 /*printf("$");*/
	while ((read = getline(&line, &len, stdin)) != -1) /*check*/
	{

		/**
		 * if (isatty(STDIN_FILENO) == 1)
		*{
		*	from_pipe = true;
		*}
		*/
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
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		_execve(line);
		write(STDOUT_FILENO, "$", 1); /*printf("$");*/
	}
	return (0);
}
