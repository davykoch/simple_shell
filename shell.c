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
