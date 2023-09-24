#include "main.h"
/**
 * _myexit - exits the shell
 *	@args:arguments provided
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(char **args)
{
	int exitcheck;

	if (args[1] != NULL) /* If there is an exit argument */
	{
		exitcheck = atoi(args[1]);
		return (exitcheck);
		/**
		 * if (exitcheck == -1)
		 *{
		 * info->status = 2;
		 * print_error(info, "Illegal number: ");
		 *	_eputs(info->argv[1]);
		 *	_eputchar('\n');
		 *	return (1);
		 *}
		 *	info->err_num = _erratoi(info->argv[1]);
		 *return (-2);
		 *
		 *exit(exit_code);
		 */
	}
	else
	{
		/**
		 * info->err_num = -1;
		 *return (-2);
		 */
		return (0); /* exit(0); */
	}
}
