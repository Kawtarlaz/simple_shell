
#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * Return: Status of the executed commands or shell termination status.
 */

int main(int argc, char **argv)
{
char *line_input = NULL;
char **command = NULL;
int status = 0, index = 0;
(void)argc;
while (1)
{
line_input = read_line_command();
if (line_input == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (status);
}
index++;
command = tokenizer_line_command(line_input);
if (command  == NULL)
continue;
if (is_builtin(command[0]))
handle_builtin(command, argv, &status, index);
else
status = execute_command(command, argv, index);
}
}
