#include "main.h"
/**
 * _myexit - exits the shell
 *	@args:arguments provided
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(char **args, char **av, int linenumber)
{
	int exit_status;
	int status;

	/* Check if an exit argument is provided */
	if (args[1])
	{
		exit_status = _erratoi(args[1]);
		if (exit_status == -1)
		{
			status = 2;
			p_error(linenumber, "Illegal number: ", av);
			_eputs(args[1]);
			_eputchar('\n');
			return (1);
		}
		return (-2);
	}
	return (-2);
}


/**
 * p_error - Print an error message with additional information.
 * @info: A pointer to the info_t structure containing shell information.
 * @estr: The error message to print.
 */
void _p_error(linenumber, char *estr, char **av)
{
	_eputs(av);
	_eputs(": ");
	_putint(linenumber, STDERR_FILENO);
	_eputs(": ");
	_eputs(argv[0]);
	_eputs(": ");
	_eputs(estr);
}
