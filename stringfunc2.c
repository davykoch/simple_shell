#include "shell.h"

/**
 * extract_substrings - Function that extracts words from a string.
 * @substr_array: Array to store extracted words.
 * @input_str: Pointer to the input string.
 * Return: array of words
 */
void extract_substrings(char **substr_array, char *input_str)
{
	int i, init_index, word_flag, len;

	len = i = init_index = word_flag = 0;

	while (input_str[i] != '\0')
	{
		if (input_str[i] == ' ' || input_str[i + 1] == '\0')
		{
			if (input_str[i] != ' ')
			{
				i++;
				word_flag = 1;
			}

			if (word_flag)
			{
				copy_segment(i - init_index, input_str + init_index, substr_array + len);
				if (!substr_array[len])
					exit(0);
				len += 1;
				init_index = i + 1;
				word_flag = 0;
			}

			if (input_str[i] == '\0')
				continue;
			i += 1;
			init_index += 1;
			continue;
		}
		else
		{
			if (!word_flag)
				init_index = i;
			word_flag = 1;
		}
		i += 1;
	}
	substr_array[len] = NULL;
}

/**
 * copy_segment - Copies a segment into a word array.
 * @seg_len: Length of segment.
 * @seg: Pointer to the segment.
 * @dest: Pointer to the destination in the array.
 */
void copy_segment(int seg_len, char *seg, char **dest)
{
	int x;

	*dest = malloc(sizeof(char) * (seg_len + 1));
	if (!(*dest))
	{
		perror("Error: memory allocation failed\n");
		free(dest);
		exit(0);
	}

	for (x = 0; x < seg_len; x++)
		(*dest)[x] = seg[x];
	(*dest)[x] = '\0';
}
