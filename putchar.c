#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char *c)
{
return (write(STDOUT_FILENO, &c, _strlen(c)));
}

/**
* _putchar_str - prints string
* @s: string to be printed
*/
void _putchar_str(const char *s)
{
	while (*s != '\0')
	{
		write(STDOUT_FILENO, &s, _strlen(s));
		s++;
	}
}
/**
 * _putint - Print an integer to the specified file descriptor
 *           with error handling.
 * @input: The integer to print.
 * @fd: The file descriptor (STDOUT_FILENO or STDERR_FILENO) to
 *      which to print.
 *
 * Return: The number of characters printed.
 */
int _putint(int input, int fd)
{
	int (*output_char)(char) = _putchar;
	int digit, count = 0;
	unsigned int absolute_value, current;

	if (fd == STDERR_FILENO)
		output_char = _eputchar;
	if (input < 0)
	{
		absolute_value = -input;
		output_char('-');
		count++;
	}
	else
		absolute_value = input;
	current = absolute_value;
	for (digit = 1000000000; digit > 1; digit /= 10)
	{
		if (absolute_value / digit)
		{
			output_char('0' + current / digit);
			count++;
		}
		current %= digit;
	}
	output_char('0' + current);
	count++;

	return (count);
}
