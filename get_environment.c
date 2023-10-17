#include "shell.h"

char *get_environment(char *env)
{
int index = 0;
char *temporary = NULL, *key = NULL, *value = NULL, *environment = NULL;

for (index = 0 ; environ[index]; index++)
{
temporary = string_duplicate(environ[index]);
key = strtok(temporary, "=");
if (string_compare(key, env) == 0)
{
value = strtok(NULL, "=");
environment = string_duplicate(value);
free(temporary);
return (environment);
}
free(temporary);

}
return (NULL);
}

