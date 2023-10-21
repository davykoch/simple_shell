#include "shell.h"

/**
 * get_env_value - Fetch the value of a specified environment variable.
 * @var_name: Name of the environment variable to retrieve.
 * @env_vars: List of all environment variables.
 * Return: Pointer to the value of the environment variable
 */
char *get_env_value(const char *var_name, char **env_vars)
{
	int loop_idx = 0, var = 0;
	int name_length, match_result;

	while (env_vars[loop_idx] != NULL)
	{
		match_result = comp_strings(var_name, (const char *)env_vars[loop_idx]);

		if (match_result == 1)
		{
			name_length = _strlen(env_vars[loop_idx]);

			while (env_vars[loop_idx][var] != '=')
				var++;
			name_length -= var;
			return (env_vars[loop_idx] + var + 1);
		}
		loop_idx++;
	}
	return (NULL);
}
