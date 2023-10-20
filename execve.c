#include "main.h"
/**
 * _execve - calls progs
 * @line:string input by user
 * @av: argument vector
 * @linenumber: line number of the line read
 * Return: void
 */
char **_execve(char *line, char **av, int linenumber)
{
	/* char *args[] = {NULL, NULL};  */ /* check*/
	char **args = (char **)malloc(sizeof(char *) * (MAX_ARGS + 1));
	int arg_count;

	if (args == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	arg_count = _spacestrtok(line, args);

	if (arg_count <= 0)
	{
		if (_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		free(args);
		freeline(&line);
		return (NULL);
	}

	if (_strcmp(args[0], "setenv") == 0)
	{
		if (!args[1] || args[2])
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
			freeline(&line);
			free(args);
			exit(EXIT_FAILURE);
		}
		if (!process_setenv(args[1], args[2]))
		{
			perror("something\n");
			freeline(&line);
			free(args);
			return (NULL);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (!args[1])
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			freeline(&line);
			free(args);
			exit(EXIT_FAILURE);
		}
		if (!process_unsetenv(args[1]))
		{
			perror("dint set\n");
			freeline(&line);
			free(args);
		}
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		_myexit(args, av, linenumber);
		free(line);
	}
	args[arg_count] = NULL;
	return (args);
	/*free(line); */
}
