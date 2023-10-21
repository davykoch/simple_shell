#include "shell.h"

/**
 * show_signal - Shows a prompt when Ctrl+C is pressed.
 * @signal_val: The received signal.
 */
void show_signal(int signal_val)
{
	if (signal_val == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
