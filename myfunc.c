#include "main.h"
/**
 * handle_hash - check if string has
 * comment (#) and voids it
 * @info:struct containing string to be checked
 *
 */

void handle_hash(info_t *info)
{
	int i = 0;

	while (info->input[i])
	{
		if (info->input[i] == '#')
		{
			info->input[i] = '\0';
			break;
		}
		i++;
	}
}
/**
 * _myexit - exits string
 * @info: info of the string
 * Return: exit status
 */
int _myexit(info_t *info)
{
	int e_status;

	if (info->args[1] != NULL) /* If there is an exit argument */
	{
		e_status = atoi(info->args[1]);
		return (e_status);
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
		return (0);/* exit(0); */
	}
}
/**
 * free_args - free args
 * @args: arguments to be freed
 * Return: void
 */
void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
