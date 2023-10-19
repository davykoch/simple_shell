#include "main.h"
/**
* handle_hash - check if string has
* comment (#) and voids it
* @line: input
* Return: line
*/

void handle_hash(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}
