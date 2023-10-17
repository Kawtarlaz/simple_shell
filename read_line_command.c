#include "shell.h"

/**
 * read_line_command - Reads a line of command from standard input.
 *
 * Return: A pointer to the read line or NULL if an error occurs.
 */

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
