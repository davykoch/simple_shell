#include "main.h"
/**
*hsh -
*
*/
void hsh(info_t *info)
{

	/* linenumber++; */
	/* size_t size = 0;	 */					/*len*/
	/* ssize_t input;  *//*what fgets stores to*/ /*changed from line*/
	char input[MAX_ARGS];

	ssize_t read;
	int i = 0;

	_memset(input, 0, MAX_ARGS);

	read = read(STDIN_FILENO, info->input, MAX_ARGS);
	/* read = getline(&input, &size, stdin); */

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
	while (input[i])
	{/*remove new line char*/
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';
			i++;
	}
	handle_hash(input);/*myfunc.c*/
	info->input = _strdup(input);
	/* Free the input array after copying its contents to info->input */
	free(input);
	if (info->input[0] == '\0')

	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
