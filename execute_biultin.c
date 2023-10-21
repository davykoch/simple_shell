#include "shell.h"

/**
 * execute_builtin_cmd - Runs the built-in commands.
 * @arguments: Array of command parameters.
 * @env_vars: Array of environment variables.
 * Return: 1 if executed successfully, 0 otherwise.
 */
int execute_builtin_cmd(char **arguments, char **env_vars)
{
	list_t command_list[] = {
		{"env", show_environment},
		{"exit", manage_exit_cmd},
		{NULL, NULL}
	};

	int index;

	if (!arguments[0])
		return (0);

	for (index = 0; index < 2; index++)
	{
		if (comp_strings(arguments[0], command_list[index].cmd_name) == 0)
		{
			return (command_list[index].ptr(arguments, env_vars));
		}
	}

	return (0);
}
