#include "main.h"
/**
 * _haspath - checks if has path
 *	@args: arguments
 * Return: void
 */
void _haspath(char **args, char *line)
{
	if (access(args[0], X_OK) == 0)
	{

		if ((execve(args[0], args, environ)) == -1)
		{
			perror("error -access");
			/* free_args(args); */
			/* free(info->input); */
			exit(EXIT_FAILURE);
		}
	}
}
