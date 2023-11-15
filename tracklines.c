#include "main.h"

/**
 * track_lines - Read and track input lines
 *
 * This function reads input lines from the user, tracks their content, and
 * returns the input as a dynamically allocated string.
 *
 * Return: A dynamically allocated string containing the user's input.
 */
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