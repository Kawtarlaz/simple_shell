#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define DELIMITER " \t\n"

extern char **environ;

char *get_environment(char *env);
char *read_line_command(void);
char *string_duplicate(const char *str);
char *get_path(char *cmd);
char **tokenizer_line_command(char *line_input);
int execute_command(char **command_to_execute , char **argv , int index);
char *string_copy(char *dest, char *src);
void free_string_array(char **array);
int string_compare(char *string1, char *string2);
int string_length(char *s);
char *string_concatenate(char *dest, char *src);
void print_error(char *name , char *cmd , int index);
void string_reverse(char *string, int length);
char *itoa_custom(int number);
int is_builtin(char *cmd);
void handle_builtin(char **cmd, char **argv, int *status, int index);
void print_environment(char **cmd, int *status);
int is_positif_integer(char *string);
void exit_shell(char **cmd, char **argv, int *status, int index );
int atoi_custom(char *string);




#endif