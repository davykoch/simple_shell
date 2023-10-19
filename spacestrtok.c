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
	char *token;  /* Change the token type to char* */
	char **tokens = strtow(line, delim);

	int i;
	for (i = 0; tokens[i] != NULL; i++)
	{
		token = tokens[i];  /* Get each individual token from tokens */
		args[arg_count++] = strdup(token);
	}

	/* Free the tokens array when you're done with it */
	free(tokens);

	return arg_count;
}