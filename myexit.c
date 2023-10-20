#include "main.h"
/**
 * _myexit - exits the shell
 *	@args:arguments provided
 * @av: hsh
 * @linenumber: linenumber
 */
void _myexit(char **args, char **av, int linenumber)
{
	int exit_status;

	/* Check if an exit argument is provided */
	if (args[1])
	{
		exit_status = _erratoi(args[1]);
		if (exit_status == -1)
		{
			_perror(linenumber, "Illegal number: ", av, args);
			_eputs(args[1]);
			_eputchar('\n');
			exit(exit_status);
		}
		exit(exit_status);
	}
	exit(EXIT_SUCCESS);
}

/**
 * _perror - Print an error message with additional information.
 * @linenumber: A pointer to the info_t structure containing shell information.
 * @estr: The error message to print.
 * @av: its the hsh
 * @args: arguments
 */
void _perror(int linenumber, char *estr, char **av, char **args)
{
	_eputs(av[0]);
	_eputs(": ");
	_putint(linenumber, STDERR_FILENO);
	_eputs(": ");
	_eputs(args[0]);
	_eputs(": ");
	_eputs(estr);
}
