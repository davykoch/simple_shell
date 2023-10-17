#include "main.h"
/**
  * _getenv - gets value of environ variable
  * @args: argument string
  * @path_token: environ path
  * Return: the string
  */
char *_getenv(char *path_token, info_t *info)
{
	char *full_path = malloc(_strlen(path_token) + _strlen(info->args[0]) + 2);
	/* stdrup*/

	_strcpy(full_path, path_token);
	_strcat(full_path, "/");
	_strcat(full_path, info->args[0]);
	return (full_path);
}
