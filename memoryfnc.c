#include "main.h"
/**
 * _memset - fill input with 0
 * @s: input
 * @b: the zero to be filled
 * @n: MAX_ARGS
 * Return: input full of char zero
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
