#include "main.h"
/**
* _parentpid - prints pid
* @pid: process id
*/
void _parentpid(pid_t pid)
{
	pid_t wpid;
	int status;

	while (1)
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		if (wpid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) || WIFSIGNALED(status))
		{
			break;
		}
	}
}
