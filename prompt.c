#include "main.h"

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
 * Return: frompipe
 */
/* int prompt_display(void) */

