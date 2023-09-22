#include "main.h"
/**
 *
 *
 */
void _execve1(char *line, char **av, int linenumber)
{
	/* handle exit*/
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS); /* Exit the shell*/
	}
	/*handle env*/
	else if (strcmp(line, "env") == 0)
	{
		/* Handle the "env" command by printing the environment variables*/
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{

		_execve(line, av, linenumber);
	}
}
