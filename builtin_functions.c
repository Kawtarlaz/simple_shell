
#include "shell.h"
int is_builtin(char *cmd)
{
    char *builtins[] = {"exit", "env", "setenv", "unsetenv", "cd", NULL};
    int index = 0;
    for (index = 0; builtins[index]; index++)
    {
        /* code */
        if (string_compare(cmd, builtins[index]) == 0)
            return (1);
    }
    return (0);
}

void handle_builtin(char **cmd, char **argv, int *status, int index)
{
    if(string_compare(cmd[0], "exit") == 0)
        exit_shell(cmd, argv, status, index );
    else if(string_compare(cmd[0], "env") == 0)
        print_environment( cmd , status);
    // else if(string_compare(cmd[0]), "setenv") == 0)
    //     set_environment(cmd[1], cmd[2]);
    // else if(string_compare(cmd[0]), "unsetenv") == 0)
    //     unset_environment(cmd[1]);
    // else if(string_compare(cmd[0]), "cd") == 0)
    //     change_directory(cmd[1]);
    // else
    //     print_error(argv[0], cmd[0], "not found");
}

void exit_shell(char **cmd, char **argv, int *status, int idx )
{
    int exit_val = (*status);
    char *index, message[]= ": Illegal number: ";
    if(cmd[1])
    {
        if(is_positif_integer(cmd[1]))
            exit_val =  atoi_custom(cmd[1]);
        else
        {
            index= itoa_custom(idx);
            write(STDERR_FILENO, argv[0], string_length(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, index, string_length(index));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, cmd[0], string_length(cmd[0]));
            write(STDERR_FILENO, message, string_length(message));
            write(STDERR_FILENO, cmd[1], string_length(cmd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(index);
            free_string_array(cmd);
            (*status) = 2;
            return;
        }
    }
    free_string_array(cmd);
    exit(exit_val);
}

void print_environment(char **cmd, int *status)
{
    int index = 0;
    for (index = 0; environ[index]; index++)
    {
        write(STDOUT_FILENO, environ[index], string_length(environ[index]));
        write(STDOUT_FILENO, "\n", 1);
    }
    free_string_array(cmd);
    (*status )= 0;
}

int is_positif_integer(char *string)
{
    int index = 0;
    for (index = 0; string[index]; index++)
    {
        if(string[index] < '0' || string[index] > '9')
            return (0);
    }
    return (1);
}

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

