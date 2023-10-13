#include "main.h"
/**
 * _spacestrtok - tokenizes strings
 * @p_info: string to tokenize
 * @args: string arguments
 * Return: count
 */
int _spacestrtok(info_t *info, char **args)
{
	char *delim = " ";

	int arg_count = 0;
	char *token = strtok(info->input, delim); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = _strdup(token); /* strdup to maintain original line*/
		token = strtok(NULL, delim);
	}
	return (arg_count);
}
