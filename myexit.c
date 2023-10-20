#include "main.h"
/**
 * _myexit - exits the shell
 *	@args:arguments provided
 * @av: hsh
 * @linenumber: linenumber
 */
void _myexit(char *line)
{
	int exit_status;
	char *msg = "not valid\n";

	/* Check if an exit argument is provided */
	if (line[0] == '\0' || line[1] == '\0')
		exit(EXIT_FAILURE);
	else
		exit_status = ato_i(&line[1]);
	if (exit_status == 0 && line[1] != 0)
	{
		write(STDERR_FILENO, msg, _strlen(msg));
		exit(EXIT_FAILURE);
	}
	exit(exit_status);
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
/**
 * ato_i - str to int
 * @t:to be changed to int
 */
int ato_i(char *t)
{
	int k = 0;
	unsigned int i = 0;
	int m = 1;
	int a = 0;

	while (t[k])
	{
		if (t[k] == 45)
		{
			m *= -1;
		}
		while (t[k] >= 48 && t[k] <= 57)
		{
			a = 1;
			i = (i * 10) + (t[k] - '0');
			k++;
		}

		if (a == 1)
		{
			break;
		}

		k++;
	}

	i *= m;
	return (i);
}