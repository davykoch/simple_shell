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
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
	{
        if (*s == c)
            return s; /*Return a pointer to the first occurrence of 'c'*/
        s++;
    }

    return NULL; /*Return NULL if 'c' is not found in the string*/
}

#include "main.h"
/**
 * _erratoi - custom string-to-integer conversion with error handling
 * @s: the string to be converted
 * @error: a pointer to an integer for error information
 *
 * Return: integer value if conversion is successful, or INT_MIN/INT_MAX on error
 * 
 * Error codes:
 *   0: No error
 *  -1: Empty string
 *  -2: Non-numeric character
 *  -3: Integer overflow
 */
int _erratoi(const char *s, int *error)
{
	int i = 0;
    int sign = 1;
    int result = 0;
	
    if (s == NULL || *s == '\0')
	{
        if (error != NULL)
		{
            *error = -1; 
        }
        return INT_MIN;
    }
	if (s[i] == '-')
	{
        sign = -1;
        i++;
    }

    while (s[i] != '\0')
	{
        if (s[i] < '0' || s[i] > '9')
		{
            if (error != NULL)
			{
                *error = -2; 
            }
            return INT_MIN;
        }

        int digit = s[i] - '0';

        if (sign == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)))
		{
            if (error != NULL)
			{
                *error = -3;
            }
            return (INT_MAX);
        } else if (sign == -1 && (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit > -(INT_MIN % 10))))
		{
            if (error != NULL)
			{
                *error = -3; 
            }
            return INT_MIN;
        }

        result = result * 10 + sign * digit;
        i++;
    }

    if (error != NULL)
	{
        *error = 0;
    }

    return (result);
}
