#include "main.h"
/**
  * _getenv - gets value of environ variable
  * @args: argument string
  * @path_token: environ path
  * Return: the string
  */
char *_getenv(char *path_token, char **args)
{
	char *full_path = malloc(strlen(path_token) + strlen(args[0]) + 2);
	/* stdrup*/

	strcpy(full_path, path_token);
	strcat(full_path, "/");
	strcat(full_path, args[0]);
	return (full_path);
}
