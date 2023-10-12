#include "shell.c"
/**
 * 
*/
void prompt(void)
{
	if (from_pipe && isatty(STDIN_FILENO))
	{
		_putchar("$-");
		/* fflush(stdout); */
	}

}