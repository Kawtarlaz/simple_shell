#include "shell.h"

char *read_line_command(void)
{
char *line = NULL;
ssize_t numberOfCharacter = 0;
size_t sizeOfLine = 0;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
numberOfCharacter = getline(&line, &sizeOfLine, stdin);
if (numberOfCharacter == -1)
{
free(line), line = NULL;
return (NULL);
}
return (line);
}
