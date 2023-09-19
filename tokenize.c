#include "main.h"
/**
 * 
*/
size_t _tokenize(char *str, char *delim, argc)
{
	char *token = strtok(line, " "); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		args[arg_count++] = _strdup(token); /* strdup to maintain original line*/
		token = strtok(NULL, " ");
	}
}