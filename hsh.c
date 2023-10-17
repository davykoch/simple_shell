#include "main.h"
/**
 *hsh - reads command
 * @info: pointer to input info
 * @from_pipe: info from pipe
 */
void hsh(info_t *info, int from_pipe)
{

	/* linenumber++; */
	/* size_t size = 0;	 */						   /*len*/
	/* ssize_t input;  */ /*what fgets stores to*/ /*changed from line*/
	/* static char input[MAX_ARGS]; */
	char *input = NULL; 
	size_t len = 0;
	ssize_t reead;
	int i = 0;

	/*  _memset(input, 0, MAX_ARGS); */ /*or INFO_INIT*/

	/* reead = read(STDIN_FILENO, input, MAX_ARGS); */
	reead = getline(&input, &len, stdin);
	if (reead == -1)
	{
		perror("read line failed"); /* check */
		free(input);
		exit(EXIT_FAILURE);
	}
	if (reead == 0) /* End of File (Ctrl+D) */
	{
		if (from_pipe && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (reead == '\0' || reead == EOF)
	{
		exit(EXIT_SUCCESS);
		free(input);
	}
	input[reead] = '\0'; /* Null-terminate the buffer */
	for (i = reead - 1; i > 0 && (input[i] == '\n' || input[i] == '\r'); i--)
	{
		input[i] = '\0';
	}

	info->input = _strdup(input);
	/* Free the input array after copying its contents to info->input */
	/* free(input); */
	handle_hash(info);  /*myfunc.c*/
	if (info->input[0] == '\0')

	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
