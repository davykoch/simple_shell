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

	write(STDOUT_FILENO, "$", 1);/*printf("$");*/
	while (1 && !from_pipe) /*check*/
	{
	read = getline(&line, &len, stdin);
	
		if (isatty(STDIN_FILENO) == 1)
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
<<<<<<< HEAD
		write(STDOUT_FILENO, "$", 1);/*printf("$");*/
		free(line);
=======
	}
	free(line);
>>>>>>> a0c27f661744e4a451a02a9056bb39a6a8f500da

	}
	return (0);	
}
