/**
* find_builtin - finds a builtin command
* @info: the parameter & return info struct
*
* Return: -1 if builtin not found,
*			0 if builtin executed successfully,
*			1 if builtin found but not successful,
*			-2 if builtin signals exit()
*/
int find_builtin(info_t *info)
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


/**
* _myexit - exits the shell
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
*  Return: exits with a given exit status
*         (0) if info.argv[0] != "exit"
*/
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1] != NULL) /* If there is an exit argument */
	{
		exitcheck = atoi(info->argv[1]);
		return exit_status;
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
