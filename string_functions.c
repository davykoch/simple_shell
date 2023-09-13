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
	while (*str++)/*calculate length of input string*/
		length++;
	newstr = malloc(sizeof(char) * (length + 1));
			if (!newstr)/*check if mem allocation was succesful*/
			return (NULL);
			for (int i = 0; i < length; i++)/*copy characters*/
			newstr = str[i];

			newstr[length] = '\0';/*Null-terminate new string*/
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
