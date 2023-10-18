#include "main.h"

/**
* _strdup -  duplicates a given input string
* @str: input string to duplicate
* Return: pointer to duplicated string
*/
char *_strdup(const char *str)
{
	int length = 0;

	char *ret;

	int i;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
		return (NULL);

	for (i = 0; i < length; i++)
		ret[i] = str[i];

	ret[length] = '\0';
	return (ret);
}
/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (ret);
}
/**
* _strchr - locates a character in a string
* @s: the string to be parsed
* @c: the char to look for
* Return: a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}
/**
 * _erratoi - converts string to integer
 * @s: string
 * Return: integer value
*/
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		} else
		{
			return (-1);
		}
	}

	return (result);
}
