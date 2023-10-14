#include "main.h"

/*This Function Free Memory After Every Allocation*/

void freestrarr(char **array)
{
    int i;

    i = 0;
    if (!array)
    {
        return;
    }
    while (array[i])
    {
        free(array[i]), array[i] = NULL;
        i++;
    }
    free(array), array = NULL;
}

void str_rev(char *buffer, int i)
{
    int j, k;
    char tmp;

    j = 0;
    k = i - 1;
    while (j < k)
    {
        tmp = buffer[j];
        buffer[j] = buffer[k];
        buffer[k] = tmp;
        j++;
        k--;
    }
}

char *_itoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    str_rev(buffer, i);

    return (_strdup(buffer));
}

void _perror(char *av, char *cmd, int cntr)
{
    char *counter;

    counter = _itoa(cntr);

    write(STDIN_FILENO, av, _strlen(av));
    write(STDIN_FILENO, ": ", 2);
    write(STDIN_FILENO, counter, _strlen(counter));
    write(STDIN_FILENO, ": ", 2);
    write(STDIN_FILENO, cmd, _strlen(cmd));
    write(STDIN_FILENO, ": not found\n", 13);

    free(counter), counter = NULL;

}