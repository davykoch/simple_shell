#include "main.h"
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL; /* stores data from cmd line*/

	size_t len = 0;
	ssize_t read;

	printf("$");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
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

		char *args[]; /* do we use malloc*/
/* strdup to maintain original line*/
		char *token = strtok(line, " "); /*separate cmds singular*/

		int arg_count = 0;

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		if (arg_count > 0)
		{
			/* where we use cmds entered */
			printf("%s", line);
			printf("$");
		}
		free(line);

		return (0);
	}
}
