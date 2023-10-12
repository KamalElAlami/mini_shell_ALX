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