#include "main.h"
/**
 * _haspath - checks if has path
 *	@args: arguments
 * @envp: environment var
 * Return: void
 */
void _haspath(char **args, char **envp, char *line)
{
	if (access(args[0], X_OK) == 0)
	{

		if ((execve(args[0], args, envp)) == -1)
		{
			perror("error -access");
			free_args(args);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
}