#include "shell.h"

/**
 * comp_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Negative value if str1 < str2, 0 if str1 == str2
 * else positive.
 */
int comp_strings(const char *str1, const char *str2)
{
	int idx = 0;

	while (str1[idx] == str2[idx])
		idx++;

	return (str1[idx] - str2[idx]);
}

/**
 * comp_n_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Negative value if st1 < str2, 0 if str1 == str2, else positive.
 */
int comp_n_strings(const char *str1, const char *str2)
{
	int idx;

	for (idx = 0; str1[idx] != '\0' || str2[idx] != '\0'; idx++)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
	}
	return (0);
}

/**
 * _strlen - Calculate length of a string.
 * @input_str: Input string.
 * Return: Length of the string.
 */
int _strlen(const char *input_str)
{
	int len = 0;

	while (input_str[len] != '\0')
		len++;

	return (len);
}

/**
 * _stringconcat - Concatenate two strings.
 * @str1: First string.
 * @str2: Second string to be appended to first string.
 * Return: Pointer to the concatenated string; else NULL.
 */
char *_stringconcat(char *str1, char *str2)
{
	char *merged_string;
	int i, j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";

	merged_string = malloc(_strlen(str1) + _strlen(str2) + 1);
	if (!merged_string)
		exit(0);

	for (i = 0; str1[i] != '\0'; i++)
		merged_string[i] = str1[i];
	for (j = 0; str2[j] != '\0'; j++)
		merged_string[i + j] = str2[j];
	merged_string[i + j] = '\0';

	return (merged_string);
}
