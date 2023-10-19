#include "main.h"
/**
 * biultin - calls the prog and
 * @line: string input by user
 * Return: int
 */
int biultin(char *line)
{
	if (_strcmp(line, "env") == 0)
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
			_putchar_str(*env);
			_putchar('\n');
			env++;
		}
		return (1);
	}
	else if (_strcmp(line, "exit") == 0)
	{
		/* free(line); */
		exit(EXIT_SUCCESS); /* Exit the shell*/
		return (1);
	}
	return (0);
}
