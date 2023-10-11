#include "main.h"
/**
 *
 *
 */
hsh(info_t *info)
{

	linenumber++;
	if (from_pipe && isatty(STDIN_FILENO))
		prompt();
	read = getline(&input, &size, stdin);

	if (read == -1)
	{
		if (feof(stdin)) /*ctrl d*/
		{
			if (from_pipe && isatty(STDIN_FILENO))
				_putchar("\n");
			/*free(input);*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("cannot get input"); /* check */
			/* free(input); */
			exit(EXIT_FAILURE);
		}
	}
	info->input = input;

	if (input[read - 1] == '\n')
		input[read - 1] = '\0';
	_execve1(&info, av, linenumber, envp);
}