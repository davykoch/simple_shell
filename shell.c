#include "shell.h"
/**
 * main - its the main shell
 * Return : 0 on success
 */
int main()
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
		printf("%s\n", line);
		printf("$");
	}

	return (0);
}
