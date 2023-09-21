#include "main.h"

/**
 * _strdup - duplicates input string 'str'
 * @str: input string
 * Return: pointer to the new string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *newstr;
	int i;

	if (str == NULL)
		return (NULL);
	while (*str++) /*calculate length of input string*/
		length++;
	newstr = malloc(sizeof(char) * (length + 1));
	if (!newstr) /*check if mem allocation was succesful*/
		return (NULL);
	for (i = 0; i < length; i++) /*copy characters*/
		newstr[i] = str[i];

	newstr[length] = '\0'; /*Null-terminate new string*/
	return (newstr);
}

/**
 * _strcpy - copies string
 * @src: source string to be copied
 * @dest: destination string where 'src' will be copied
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp compares two strings
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 if they are equal
 * otherwise perform lexicographical difference
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
		return (dest);

	char *ret = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (ret);
}

/**
 * _strlen - returns length of a string
 * @s: string to check its length
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
