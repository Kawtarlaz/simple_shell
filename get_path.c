#include "shell.h"

char *get_path(char *cmd) {

    char *path_environment = NULL, *directory = NULL, *full_cmd = NULL;
    struct stat state;
    int index;

    for(index=0 ; cmd[index] ; index++ ){
        if (cmd[index] == '/'){
            if(stat(cmd, &state) == 0){
                return (string_duplicate(cmd));
            }
            return NULL;
        }
    }

    path_environment = get_environment("PATH");
    if(!path_environment)
        return (NULL);
    
    directory = strtok(path_environment, ":");
    while(directory){
        full_cmd = malloc(string_length(directory) + string_length(cmd) + 2);
        if(full_cmd )
        {
            string_copy(full_cmd, directory);
            string_concatenate(full_cmd, "/");
            string_concatenate(full_cmd, cmd);
            if(stat(full_cmd, &state) == 0)
            {
                free(path_environment);
                return (full_cmd);
            }
            free(full_cmd), full_cmd = NULL;
            directory = strtok(NULL, ":");
        }
    }
    free(path_environment);
    return NULL;
}

