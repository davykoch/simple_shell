#include "main.h"

/**
* main - its the main shell
* @ac: argument count
* @av: argument vector
* @envp: environment variable
* Return: 0 on success
*/
int main(void)
{
	info_t info[] = {INFO_INIT};
	int from_pipe;

	from_pipe = is_input();

	while (1) /*check*/
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		hsh(info, from_pipe);
		_execve1(info);
		/* return (0); */
		free(info->input);
	}
}
