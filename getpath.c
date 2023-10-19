#include "main.h"
/**
 * _getpath - runs excve if no path entered by user
 * @line: line read
 * @args: args from getline
 * @av: argument vector
 * @linenumber: line number of the line read
 * @envp: environment variable
 * Return:void
 */
void _getpath(char *line, char **args, char **av, int linenumber)
{
	char *path = getenv("PATH");
	char *path_token = strtok(path, ":");

	while (path_token != NULL)
	{
		char *full_path = _getenv(path_token, args);

		if (access(full_path, X_OK) == 0)
		{
			int exve = execve(full_path, args, environ);

			if (exve == -1)
			{
				perror("error -execve");
				free(line);
				free(full_path);
				exit(EXIT_FAILURE);
			}
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	/*/ If we reach here, the command was not found in PATH*/
	/*fprintf(stderr, "Command not found: %s\n", args[0]);*/
	/*perror("command not found");*/
	fprintf(stderr, "%s: %d: %s: not found\n", av[0], linenumber, args[0]);

	free(line);
	exit(EXIT_FAILURE);
}
