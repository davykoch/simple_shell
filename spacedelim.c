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
	char *token = strtok(line, delim); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = strdup(token); /* strdup to maintain original line*/
		token = strtok(NULL, delim);
	}
	return (arg_count);
}
