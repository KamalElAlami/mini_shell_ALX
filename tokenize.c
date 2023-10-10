#include "main.h"

char **tokenize(char *line)
{
    char *tok;
    char **cmd;
    char *temp;
    int count;
    int i;

    tok = NULL;
    cmd = NULL;
    temp = NULL;
    count = 0;
    i = 0;
    if (!line)
    {
        return (NULL);
    }
    temp = _strdup(line);
    tok = strtok(temp, DELIMI);
    if (tok == NULL)
    {
        free(line), line = NULL;
        free(temp), temp = NULL;
        return (NULL);
    }
    while (tok)
    {
        count++;
        tok = strtok(NULL, DELIMI);
    }
    free(temp), temp = NULL;

    cmd = malloc(sizeof(char *) * (count + 1));
    if (!cmd)
    {
        free(line), line = NULL;
        return (NULL);
    }

    tok = strtok(line, DELIMI);
    while (tok)
    {
        cmd[i++] = _strdup(tok);
        tok = strtok(NULL, DELIMI);
    }
    cmd[i] = NULL;
    free(line), line = NULL;
    return (cmd);
}