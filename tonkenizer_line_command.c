#include "shell.h"

char **tokenizer_line_command(char *line_input)
{
    char *tok = NULL, *temporary = NULL;
    char **cmd = NULL;
    int countTok = 0, index = 0;

    if(!line_input)
        return (NULL);

    temporary = string_duplicate( line_input);

    tok = strtok(temporary, DELIMITER);
    
    /* If the user send an empty string*/
    if(tok == NULL) 
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

    /*S'il ne reste plus de mémoire libérer la mémoire de line_input et arreter la boucle*/
    if(!cmd)
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