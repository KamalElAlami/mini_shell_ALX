#include "main.h"

char *track_lines(void)
{
    char *line;
    size_t len;
    ssize_t llen;

    line = NULL;
    len = 0;
    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    }
    llen = getline(&line, &len, stdin);

    if (llen == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}