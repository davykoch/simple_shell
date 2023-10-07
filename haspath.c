#include "main.h"
/**
 * _haspath - checks if has path
 * @p_info: all info
 *	@args: arguments
 * @envp: environment var
 * @line: getline line
 * Return: void
 */
void _haspath(info_t *p_info, char **args, char **envp)
{
	if (access(args[0], X_OK) == 0)
	{

		if ((execve(args[0], args, envp)) == -1)
		{
			perror("error -access");
			free_args(args);
			/* free(p_info->input); */
			exit(EXIT_FAILURE);
		}
	}
}
