#include "main.h"
/**
*
*
*/
ssize_t _getline(char **line, size_t *n)
{

	static char buffer[MAX_LINE];

	static size_t buffer_pos = -1;
	static size_t buffer_size = -1;
	char current_char;
	size_t line_size;

	if (buffer_pos >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, MAX_LINE);
		if (buffer_size <= 0)
		{
			return (-1);
		}
		buffer_pos = 0;
	}

	line_size = 0;

	while (buffer_pos < buffer_size)
	{
		if (line_size >= *n - 1)
		{
			*n *= 2;
			*line = realloc(*line, *n);
		}

		current_char = buffer[buffer_pos++];

		(*line)[line_size++] = current_char;

		if (current_char == '\n')
		{
			(*line)[line_size] = '\0';
			return (line_size);
		}
	}

	(*line)[line_size] = '\0';
	return (line_size);
}
