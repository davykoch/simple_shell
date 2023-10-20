#include "main.h"
/**
* _spacestrtok - tokenizes strings
* @line: string to tokenize
* @s: string arguments
* Return: count
*/
char **_spacestrtok(char *line, char **s)
{
	char *delim = " \n\t\r";
	char *p = NULL;
	int arg_count = 0;

	p = strtok(line, delim);

	while (p)
	{
		s[arg_count++] = p;
		p = strtok(NULL, delim);
	}
	s[arg_count] = NULL;
	return (s);
}
