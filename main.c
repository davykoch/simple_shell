#include "shell.h"

/**
 * main- Starting point
 * @args_count: number of parameters
 * @args_values: array of parameters
 * @env_vars: environment variables
 * Return: 0 upon successful completion
 */
int main(int args_count, char *args_values[], char **env_vars)
{
	char *user_input = NULL;
	char **cmds = NULL;
	int process_stat;
	pid_t child_process;
	(void)args_count;

	while (1)
	{
		user_input = NULL;
		signal(SIGINT, show_signal);
		if (show_command_prompt(&user_input) == -1)
			continue;
		cmds = string_tok(user_input);
		if (!cmds)
		{
			release_strings(99, 1, user_input);
			continue;
		}
		release_strings(99, 1, user_input);
		if (execute_builtin_cmd(cmds, env_vars))
			continue;
		child_process = fork();
		if (child_process == 0)
		{
			locate_cmd_path(cmds, env_vars);
			if (execve(cmds[0], cmds, NULL) == -1)
			{
				perror(*args_values);
				free_cmd_list(cmds);
				exit(0);
			}
		}
		else
		{
			free_cmd_list(cmds);
			if (!wait(&process_stat))
				break;
		}
	}
	return (0);
}
