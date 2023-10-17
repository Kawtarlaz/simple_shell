#include "shell.h"


/**
 * tokenizer_line_command - Tokenizes a command line into an array of strings.
 * @line_input: The command line string to be tokenized.
 *
 * Return: A pointer to an array of strings (tokens) if successful, otherwise NULL.
 */

char **tokenizer_line_command(char *line_input)
{
char *tok = NULL, *temporary = NULL;
char **cmd = NULL;
int countTok = 0, index = 0;

if (!line_input)
return (NULL);
temporary = string_duplicate(line_input);
tok = strtok(temporary, DELIMITER);
if (tok == NULL)
{
free(line_input), line_input = NULL;
free(temporary), temporary = NULL;
return (NULL);
}
while (tok)
{
countTok++;
tok = strtok(NULL, DELIMITER);
}
free(temporary), temporary = NULL;
cmd = malloc(sizeof(char *) * (countTok + 1));
if (!cmd)
{
free(line_input), line_input = NULL;
return (NULL);
}
tok = strtok(line_input, DELIMITER);
while (tok)
{
cmd[index] = string_duplicate(tok);
tok = strtok(NULL, DELIMITER);
index++;
}
free(line_input), line_input = NULL;
cmd[index] = NULL;
return (cmd);
}
