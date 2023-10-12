#include "main.h"

/*Command Execute Function*/

int _exec(char **cmd, char **av)
{
    pid_t clone;
    int stts;

    clone = fork(); /* create a fork from the execve and run only the child */
    if (clone == 0) /* child returns 0 and the parent returns pid*/
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(av[0]);
            freestrarr(cmd);
            exit(0);
        }
    }
    else
    {
        waitpid(clone, &stts, 0); 
        freestrarr(cmd);
    }
    return (WEXITSTATUS(stts));
}