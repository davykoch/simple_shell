#include "main.h"
/**
 * _haspath - checks if has path
<<<<<<< HEAD
 *	@args: arguments
=======
 * @args: arguments
>>>>>>> refs/remotes/origin/master
 * Return: void
 */
void _haspath(info_t *info)
{
	if (access(info->args[0], X_OK) == 0)
	{

		if ((execve(info->args[0], info->args, environ)) == -1)
		{
			perror("error -access");
			/* free_args(args); */
			/* free(info->input); */
			exit(EXIT_FAILURE);
		}
	}
}
