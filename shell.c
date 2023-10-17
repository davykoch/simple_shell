#include "main.h"

/**
<<<<<<< HEAD
* main - its the main shell
* @ac: argument count
* @av: argument vector
* Return: 0 on success
*/
=======
 * main - its the main shell
 * Return: 0 on success
 */
>>>>>>> refs/remotes/origin/master
int main(void)
{
	info_t info[] = {INFO_INIT};
	int from_pipe;

	from_pipe = is_input();

	while (1)
	{
		if (from_pipe && isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}
		hsh(info, from_pipe);
		_execve1(info);
		/* return (0); */
		free(info->input);
	}
}
