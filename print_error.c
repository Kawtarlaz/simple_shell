#include "shell.h"

void print_error(char *name , char *cmd , int index)
{
    char *i = itoa_custom(index);
    write(STDERR_FILENO, name, string_length(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, i, string_length(i));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, string_length(cmd));
    write(STDERR_FILENO, ": not found\n", 12);
    free(i);
}
    


char *itoa_custom(int number){
    char buf[20];
    int index = 0;
    if(number == 0)
        buf[index] = '0';
    else{
        while(number > 0){
            buf[index] = number % 10 + '0';
            number = number / 10;
            index++;
        }
    }
    buf[index] = '\0';
    string_reverse(buf , index);
    return (string_duplicate(buf));

}

void string_reverse(char *string, int length){
    int start = 0;
    int end = length - 1;
    char temp;
    while(start < end){
        temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}
