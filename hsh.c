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
	static char input[MAX_ARGS];

	ssize_t reead;
	int i = 0;

	_memset(input, 0, MAX_ARGS);/*or INFO_INIT*/

	reead = read(STDIN_FILENO, input, MAX_ARGS);
	/* read = getline(&input, &size, stdin); */

	if (reead == -1)
	{
		if (feof(stdin)) /*ctrl d*/
		{
			if (info->from_pipe && isatty(STDIN_FILENO))
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
		if (input[reead - 1] == '\n')
		{
			input[reead - 1] = '\0';
			i++;
		}
	}
	info->input = _strdup(input);
	/* Free the input array after copying its contents to info->input */
	/* free(input); */
	handle_hash(info);/*myfunc.c*/
	if (info->input[0] == '\0')

	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
