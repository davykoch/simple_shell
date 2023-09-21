#include "main.h"
/**
 * 
 * 
*/
char *__strchr(const char *string, char c)
{
	while (*string != c && *string != '\0')
	{
		string++;
	}
	if (*string == c)
		return ((char *)string);
	else
		return (NULL);
}
