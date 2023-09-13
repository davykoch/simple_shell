#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

int _execve(char *line);

/*string functions*/
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);

#endif /*MAIN_H*/
