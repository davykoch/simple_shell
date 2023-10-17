#include "shell.c"

/**
* is_input - checks for interactive
* Return: integer value
*/
int is_input(void)
{

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* prompt - checks interactive and prints prompt
* @info: all infor
*/
void prompt(info_t *info)
{
	int from_pipe;

	from_pipe = is_input();
	if (from_pipe && isatty(STDIN_FILENO))
	{
		info->from_pipe = _strdup(from_pipe);
		_putchar("$-");
		/* fflush(stdout); */
		/* free(from_pipe);*check*/
	}
}
