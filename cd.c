#include "header.h"
// in this file we handle cd command anf related arguments

ll CD(char **args)
{
    // if input is just cd
    if (args[1]==NULL)
    {
        chdir(root);
        return 1;        
    } 
    
    // when input contains more than 1 argument (cd expects max 1)
    if (args[2]!=NULL)
    {
        perror("Couldn't run cd command");
        return 1;        
    }
    // if path given as root
    if (strcmp(args[1], "~") == 0)
    {
        chdir(root);
        return 1;
    }
    // if path given as current directory
    if (strcmp(args[1], ".") == 0)
    {
        return 1;
    }
    // if address relarive to home is given
    if (args[1][0] == '~') 
    {
        char *path=(char *) malloc(1234*sizeof(char));
        
        sprintf(path, "%s/%s", root, args[1] + 2);
        if (chdir(path) < 0)
            perror("Path error");
        free(path);
        return 1;
    }
    if (chdir(args[1]) < 0)
    {
        perror("Path error");
        return 1;
    }
}
