#include "shell.h"

/**
 * execute_command - Executes a given command in a new process.
 * @command_to_execute: An array of ptrs containing the cmd and its arguments.
 * @argv: The program's argument vector (typically from main).
 * @index: The current command number (how many commands have been processed).
 *
 * Return: The status of the executed command.
 */

int execute_command(char **command_to_execute, char **argv, int index)
{
char *full_command;
pid_t child_pid;
int status;

full_command = get_path(command_to_execute[0]);
if (!full_command)
{
print_error(argv[0], command_to_execute[0], index);
free_string_array(command_to_execute);
return (127);
}


child_pid = fork();
if (child_pid == 0)
{
 /* Child process */
if (execve(full_command, command_to_execute, environ) == -1)
{
free(full_command), full_command = NULL;
free_string_array(command_to_execute);
}
}
else
{
waitpid(child_pid, &status, 0);
free_string_array(command_to_execute);
free(full_command), full_command = NULL;
}
return (WEXITSTATUS(status));
}
