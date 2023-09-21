#include "main.h"

/**
* _strtok - Tokenize a string based on a specified delimiter.
* @str: The string to be tokenized.
* @delim: specifies the tokenization.
* Return: Pointer to token string.
*/

char *custom_strtok(char *str, const char *delim)
{

	if (str != NULL)
	{
		static char *next_token = NULL;

		next_token = str;
	}

	if (next_token == NULL || *next_token == '\0')
	{
		return (NULL);
	}

	// Skip leading delimiters
	while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
	{
		next_token++;
	}

	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	char *token_start = next_token;

	bool found_delim = false;

	while (*next_token != '\0')
	{
		if (strchr(delim, *next_token) != NULL)
		{
			found_delim = true;
			*next_token = '\0';
			next_token++;
			break;
		}
		next_token++;
	}

	if (found_delim)
	{
		return (token_start);
	}
	else
	{
		return (NULL);
	}
}
