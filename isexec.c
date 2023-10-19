#include "main.h"
/**
 * _isexec - finds if its executable
 * @args: from getline
 * Return:bool;
 */
bool _isexec(char **args)
{
	char *epath = getenv("PATH");

	char *epath_token = strtok(epath, ":");

	while (epath_token != NULL)
	{

		char *efull_path = malloc(strlen(epath_token) + strlen(args[0]) + 2);
		/* stdrup*/

		_strcpy(efull_path, epath_token);
		_strcat(efull_path, "/");
		_strcat(efull_path, args[0]);

		if (access(efull_path, X_OK) == 0)
		{
			free(efull_path);
			return (true);
		}
		free(efull_path);
		epath_token = strtok(NULL, ":");
	}
	return (false);
}
