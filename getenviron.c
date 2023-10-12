#include "main.h"

char *_getenviron(char *cmd)
{
    char *strt, *val, *targ, *temp;
    int i;

    i = 0;
    while (environ[i])
    {
        temp = _strdup(environ[i]);
        strt = strtok(temp, "=");
        if (_strcmp(strt, cmd) == 0)
        {
            val = strtok(NULL, "\n");
            targ = _strdup(val);
            free(temp);
            return (targ);
        }
        free(temp), temp = NULL;
        i++;
    }
    return (NULL);
}