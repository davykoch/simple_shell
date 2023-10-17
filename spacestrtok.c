#include "main.h"
/**
* _spacestrtok - tokenizes strings
* @info: string to tokenize
* @args: string arguments
* Return: count
*/
int _spacestrtok(info_t *info, char **args)
{
	char *delim = " ";

	int arg_count = 0;

	const char **dup_args;

	int i;

	char *token = strtok(info->input, delim); /*separate cmds singular*/

	while (token != NULL) /*free token free args some where*/
	{
		(*args)[arg_count] = _strdup(token);
		if (*args[arg_count] == NULL)
		{
		/*  // Handle memory allocation error */
			perror("Error: memory allocation");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		arg_count++;
	}
	dup_args = (const char **)malloc((arg_count + 1) * sizeof(const char *));

	if (dup_args == NULL)
	{
		/* Handle memory allocation error*/
		perror("Error: memory allocation");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < arg_count; i++)

	{
		dup_args[i] = (*args)[i];
	}
	dup_args[arg_count] = NULL;

	info->args = dup_args;
	free_args(args);
	return (arg_count);
}
