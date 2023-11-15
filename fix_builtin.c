#include "main.h"

/**
 * check_builtin - Check if a command is a built-in shell command
 *
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */

int check_builtin(char *cmd)
{
	int i = 0;
	char *builts[] = {"cd", "env", "setenv", "exit", NULL};

	while (builts[i])
	{
		if (_strcmp(cmd, builts[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * fix_builtin - Execute built-in shell commands
 *
 * @cmd: An array of strings representing the command and its arguments.
 * @av: An array of strings representing the program name and its arguments.
 * @stts: A pointer to the exit status.
 * @i: The line number where the command was executed.
 */

void fix_builtin(char **cmd, char **av, int *stts, int i)
{
	(void)av;
	(void)i;
	// if (_strcmp(cmd[0], "cd") == 0)
	// 	change_dir();
	if (_strcmp(cmd[0], "env") == 0)
		put_env(cmd, stts);
	// else if (_strcmp(cmd[0], "setenv") == 0)
	// 	set_env();
	else if (_strcmp(cmd[0], "exit") == 0)
		shell_exit(cmd, av, stts, i);

}

/**
 * shell_exit - Exit the shell with a specified exit status
 *
 * @cmd: An array of strings representing the command and its arguments.
 * @av: An array of strings representing the program name and its arguments.
 * @stts: A pointer to the exit status.
 * @i: The line number where the command was executed.
 */

void shell_exit(char **cmd, char **av, int *stts, int i)
{
	int exv;
	char msg[] = ": exit: Illegal number: ";

	exv = (*stts);
	if (cmd[1])
	{
		if (check_sign(cmd[1]))
		{
			exv = _atoi(cmd[1]);
		}
		else
		{
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, _itoa(i), _strlen(_itoa(i)));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(i);
			freestrarr(cmd);
			return;
		}
	}
	freestrarr(cmd);
	exit(exv);
}

/**
 * put_env - Print environment variables to the standard output
 *
 * @cmd: An array of strings representing the command and its arguments.
 * @stts: A pointer to the exit status.
 */

void put_env(char **cmd, int *stts)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freestrarr(cmd);
	(*stts) = 0;
}
