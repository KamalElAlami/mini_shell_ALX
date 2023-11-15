#include "main.h"

/**
 * _exec - Execute a command
 *
 * This function executes a command by creating a child process using
 * `fork()` and then calling `execve()` in the child process. It also
 * handles command not found errors and returns the exit status of the
 * executed command.
 *
 * @cmd: An array of strings representing the command and its arguments.
 * @av: An array of strings representing the program name and its arguments.
 * @cnter: The line number where the command was executed.
 *
 * Return: The exit status of the executed command.
 */

int	_exec(char **cmd, char **av, int cnter)
{
	pid_t clone;
	char *fcmd;
	int stts;

	fcmd = _pathenviron(cmd[0]);
	if (!fcmd)
	{
		_perror(av[0], cmd[0], cnter);
		freestrarr(cmd);
		return (127);
	}
	clone = fork(); /* create a fork from the execve and run only the child */
	if (clone == 0) /* child returns 0 and the parent returns pid*/
	{
		if (execve(fcmd, cmd, environ) == -1)
		{
			free(fcmd), fcmd = NULL;
			freestrarr(cmd);
		}
	}
	else
	{
		waitpid(clone, &stts, 0);
		freestrarr(cmd);
		free(fcmd), fcmd = NULL;
		}
		return (WEXITSTATUS(stts));
}
