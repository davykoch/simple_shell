#include "main.h"
/**
 * handle_hash - check if string has
 * comment (#) and voids it
 * @info:struct containing string to be checked
 *
 */

void handle_hash(info_t info)
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
* _myexit - exits the shell
* @info: Struct containing arguments. Used to maintain
*          constant function prototype.
*  Return: exits with a given exit status
*         (0) if info.argv[0] != "exit"
*/
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1] != NULL) /* If there is an exit argument */
	{
		exitcheck = _atoi(info->argv[1]);
		return (exit_status);
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
	 return 0;/* exit(0); */
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

/**
* find_builtin - finds a builtin command
* @info: the parameter & return info struct
*
* Return: -1 if builtin not found,
*			0 if builtin executed successfully,
*			1 if builtin found but not successful,
*			-2 if builtin signals exit()
*/
int find_builtin(info_t *p_info)
{
	int i;

	/*built_in_ret = -1;*/
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			 return (builtintbl[i].func(info));
		}
	}
	return (-1);
}

/**
* find_cmd - finds a command in PATH
* @info: the parameter & return info struct
*
* Return: void
*/
void find_cmd(info_t *info)
{
	char *path = NULL;

	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
