#include "main.h"

int main(int ac, char **av)
{
    char *line;
    /*char **cmd;*/
    int stts;
    (void) ac;
    (void) av;

    line = NULL;
    /*cmd = NULL;*/
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
        printf("%s", line);
        free(line);

        /*cmd = tokenize(line);
        stts = _exec(command, av);*/
    }
}