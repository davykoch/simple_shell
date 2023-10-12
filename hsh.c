#include "main.h"
/**
 *
 *
 */
hsh(info_t *info)
{

	/* linenumber++; */
	/* size_t size = 0;	 */					/*len*/
	/* ssize_t input;  *//*what fgets stores to*/ /*changed from line*/
	char input[MAX_PROMPT];
    ssize_t read;
	int i = 0;
	mem_set(input, 0, MAX_PROMPT);

	read = read(STDIN_FILENO, input, MAX_PROMPT);
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
	{
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';
			i++;
	}
	handle_hash(input);/*myfunc.c*/
	info->input = strdup(input);
	if (input[0] == '\0')
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}