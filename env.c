#include "main.h"
/**
 * print_environment_variables - Print a list of environment variables.
 * @head: A pointer to the head of the linked list of environment variables.
 *
 * Return: The number of environment variables printed.
 */
size_t print_env(const )
{
	size_t i = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}
