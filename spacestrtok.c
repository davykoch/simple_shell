#include "main.h"
/**
 * _spacestrtok - tokenizes strings
 * @line: string to tokenize
 * @args: string arguments
 * Return: count
 */
int _spacestrtok(char *line, char **args)
{
	char *delim = " ";

	int arg_count = 0;
	/* char *token = strtow(line, delim); */ /*separate cmds singular*/
	char **token = strtow(NULL, delim);
	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = strdup(token); /* strdup to maintain original line*/
		token = strtow(NULL, delim);
	}
	return (arg_count);
}
