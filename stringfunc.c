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

    if (str == NULL)
        return (NULL);

    while (str[length] != '\0')
        length++;

   ret = malloc(sizeof(char) * (length + 1));
   
    if (!ret)
        return (NULL);

    for (int i = 0; i < length; i++)
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
    do
    {
        if (*s == c)
            return (s); /*Return a pointer to the first occurrence of 'c'*/
    }
    while (*s++ != '\0'); /*Keep searching until the end of the string*/

    return (NULL); /*Return NULL if 'c' is not found in the string*/
}