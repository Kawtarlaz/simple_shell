#include "shell.h"

/**
 * free_string_array - frees a dynamically allocated array of strings
 * @array: the array of strings to free
 *
 */

void free_string_array(char **array)
{
int index = 0;
if (!array)
return;
for (index = 0; array[index] ; index++)
free(array[index]), array[index] = NULL;
free(array), array = NULL;
}
