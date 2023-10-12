#include "main.h"

int main(int ac, char **av)
{
    char *line;
    char **cmd;
    int stts;
    (void) ac;

    line = NULL;
    cmd = NULL;
    stts = 0;
    while (1)
    {
        line = track_lines();
        if (line == NULL) /* Bach ila clickina ctrl+D Ikhrej*/
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            return (stts);
        }

        cmd = tokenize(line);
        if (cmd == NULL)
        {
            continue;
        }

        stts = _exec(cmd, av);
    }
}