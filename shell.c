#include "main.h"
/**
* free_args - free args
* @args: arguments to be freed
* Return: void
*/
void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
/**
* is_input - checks for interactive
* Return: integer value
*/
int is_input(void)
{

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
* main - its the main shell
* @ac: argument count
* @av: argument vector
* @envp: environment variable
* Return: 0 on success
*/
int main(int ac, char **av, char **envp)
{
	/* info_t *p_info; */
	 info_t p_info[] = { INFO_INIT };
	size_t size = 0;/*len*/
	ssize_t input; /*what fgets stores to*//*changed from line*/
	int from_pipe;


	/* p_info = malloc(sizeof(info_t));
	if (p_info == NULL)
		return (NULL); */

	int linenumber = 0;

	char *input = NULL; /* stores string from cmd line*/

	(void)ac;
	from_pipe = is_input();
	while (1) /*check*/
	{
		linenumber++;
		if (from_pipe && isatty(STDIN_FILENO))
			prompt();
		read = getline(&input, &size, stdin);

		if (read == -1)
		{
			if (feof(stdin))/*ctrl d*/
			{
				if (from_pipe && isatty(STDIN_FILENO))
					_putchar("\n");
				/* free(input); */
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("cannot get input"); /* check */
				/* free(input); */
				exit(EXIT_FAILURE);
			}
		}
		p_info->input = input;
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';
		_execve1(av, linenumber, envp);
	}
	/* free(line); */
	return (0);
}
