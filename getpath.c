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
void _getpath(info_t *info, char **args)
{
	char *path = getenv("PATH");
	char *path_token = _strtok(path, ":");/*custom?*/

	while (path_token != NULL)
	{
		char *full_path = _getenv(path_token, args);

		if (access(full_path, X_OK) == 0)/*can path be accessed*/
		{
			int exve = execve(full_path, arg);

			if (exve == -1)
			{
				perror("error -execve");
				/* free(p_info->input); */
				free(full_path);
				exit(EXIT_FAILURE);
			}
		}
		free(full_path);
		path_token = strtok(NULL, ":");/*adds delimiter*/
	}
	/*/ If we reach here, the command was not found in PATH*/
	/*fprintf(stderr, "Command not found: %s\n", args[0]);*/
	/*perror("command not found");*/
	/*error should be sent to _Exit() */
	fprintf(stderr, "%s: %d: %s: not found\n", av[0], linenumber, args[0]);

	/* free(p_info->input); */
	exit(EXIT_FAILURE);
}
