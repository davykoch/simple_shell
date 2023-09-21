#include "main.h"
/**
* _exit - exits shell with specified exit status
* @info: structure containing potenial arguments
* Return: 0 if exit is successful
* 1, if there is an error(invalid argument)
*/
int _exit(info_t *info)
{
	if (info->arg[1]) /*if there is an exit argument*/
	{
		int exit_status = _erratoi(info->argv[1]);

		if (exit_status == -1)
		{
			info->status = 2;
			write(STDERR_FILENO, "shell: exit: ", 13);
			write(STDERR_FILENO, info->argv[1], _strlen(info->argv[1]));
			write(STDERR_FILENO, ": numeric argument required\n", 27);

			return (1); /*error: invalid argument*/
		}
		info->err_num = exit_status;
	}
	else
	{
		info->err_num = -1; /*default exit status*/
	}
	return (0); /*success: exit with specified status*/
}
