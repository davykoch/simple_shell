#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++; /*Increment 'i' for each character in the string*/
	return (i);
}
/**
 * _strcpy - copies a string from source to destination
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

/*Copy characters from src to dest until null terminator is encountered*/
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	/*Null-terminate the destination string*/
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: sring 2
 * Return: an integer value based on the comparison result.
 */
int _strcmp(char *str1, char *str2)
{
	int k;

	for (k = 0; str1[k] != '\0' && str2[k] != '\0'; k++)
	{
		if (str1[k] != str2[k])
			return (str1[k] - str2[k]);
	}
	return (0);
}
/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
