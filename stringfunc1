#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
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

    /*Copy characters from source to destination until a null terminator is encountered*/
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
 * @s1: string 1
 * @s2: sring 2
 * Return: an integer value based on the comparison result. 
*/
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2); /*Compare ASCII values of characters*/
        s1++;
        s2++;
    }

    /*If we reach this point, either one or both strings have ended.*/
    /*Compare the remaining characters or check if both strings are equal.*/

    if (*s1 == *s2)
        return 0; /*Both strings are equal*/
    else
        return (*s1 < *s2 ? -1 : 1); /*Compare based on ASCII values*/
}