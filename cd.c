#include "header.h"
ll CD(char **args)
{
    if (args[1]==NULL)
    {
        chdir(root);
        return 1;        
    } // just cd
    
    if (args[2]!=NULL) // more than 1 argument
    {
        perror("Couldn't run cd command");
        return 1;        
    }
        // print_err("cd: too many arguments!\nUsage: cd [path]");
    if (strcmp(args[1], "~") == 0)
    {
        chdir(root);
        return 1;
    }
    if (strcmp(args[1], ".") == 0)
    {
        return 1;
    }
    if (args[1][0] == '~') // if relative to home address is given
    {
        // char *path = memalloc_str(1024 * 4);
        char *path=(char *) malloc(1234*sizeof(char));


        sprintf(path, "%s/%s", root, args[1] + 2);
        // if (debug_exec_cd)
        //     printn_debug(path);
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