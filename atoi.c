#include "shell.h"

int atoi_custom(char *string)
{
int index = 0;
int number = 0;
for (index = 0; string[index]; index++)
{
number = number * 10 + string[index] - '0';
}
return (number);
}
