#include "shell.h"

void free_string_array(char **array)
{
    int index = 0;

    if (!array)
        return;
    for (index = 0; array[index] ; index++)
            free(array[index]), array[index] = NULL;        
    free(array), array = NULL;
}