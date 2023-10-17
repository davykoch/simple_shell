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
	int linenumber = 0;

	info_t info[] = { INFO_INIT };
	info->fname = av[0];
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}

	while (1) /*check*/
	{
		linenumber++;
		prompt(info);
		hsh(info);
		_execve1(info);
		/* return (0); */
		free(info->input);
	}
}
