#ifndef MAIN_H
# define MAIN_H

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

#define DELIMI " \t\n"
extern char **environ;

char *track_lines(void);
char **tokenize(char *line);
void freestrarr(char **array);
int _exec(char **cmd, char **av, int counter);
char *_pathenviron(char *cmd);
char *_getenviron(char *cmd);
void _perror(char *av, char *cmd, int cntr);
char *_itoa(int n);
void str_rev(char *buffer, int i);


int _strlen(char *s);
int	_isdigit(int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);

int check_builtin(char *cmd);
void fix_builtin(char **cmd, char **av, int *stts, int i);
void shell_exit(char **cmd, char **av, int *stts, int i);
void put_env(char **cmd, int *stts);
int	_atoi(const char *str);


#endif
