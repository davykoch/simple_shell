#include "shell.h"
/**
 * main - its the main shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (read == 0) /* handles EOF */
		{
			break;
		}
		if (read == -1)
		{
			perror("cannot get line");
			exit(EXIT_FAILURE);
		}
		printf("%s\n", line);
		printf("$");
	}
	perror("cannot get line");
	free(line);

	return (0);
}
