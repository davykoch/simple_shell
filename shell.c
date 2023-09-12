#include "main.h"
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
		if (read == 0) /* handles EOF - ctrl-d */
		{
			break;
		}
		if (read == -1)
		{
			perror("cannot get line");/* check */
			free(line);
			exit(EXIT_FAILURE);
		}
		printf("%s", line);
		printf("$");
	}
	perror("ctrl d worked");
	free(line);

	return (0);
}
