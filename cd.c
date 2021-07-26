#include "header.h"
// in this file we handle cd command and related arguments

ll CD(char **args)
{
    // if input is just cd
    if (args[1]==NULL)
    {
        chdir(root);
        for(int i=0; i<1024; i++)
        {
            prev[i] = root[i];
        }
        return 1;
    }
    if(strcmp(args[1], "-")!=0)
    {
        getcwd(prev, 1024);
    }
    // when input contains more than 1 argument (cd expects max 1)
    if (args[2]!=NULL)
    {
        perror("Couldn't run cd command");
        done[0]=':';
        done[1]='(';
        return 1;
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
    if(strcmp(args[1], "-")==0)
    {
        char temp[1024];
        getcwd(temp, 1024);
        printf("%s\n", prev);
        if(chdir(prev)<0)
        {
            perror("Path error:");
            done[0]=':';
            done[1]='(';
            return 1;
        }
        else
        {
            done[0]=':';
            done[1]=')';
        }
        for(int i=0; i<1024; i++)
        {
            prev[i] = temp[i];
        }
        return 1;
    }
    // if path given as root
    if (strcmp(args[1], "~") == 0)
    {
        chdir(root);
        for(int i=0; i<1024; i++)
        {
            prev[i] = root[i];
        }
        return 1;
    }
    // if path given as current directory
    if (strcmp(args[1], ".") == 0)
    {
        return 1;
    }
    // if address relative to home is given
    if (args[1][0] == '~')
    {
        char *path=(char *) malloc(1234*sizeof(char));

        sprintf(path, "%s/%s", root, args[1] + 2);
        if (chdir(path) < 0)
        {
            done[0]=':';
            done[1]='(';
            perror("Path error");
        }
        else
        {
            done[0]=':';
            done[1]=')';
        }
        free(path);
        return 1;
    }
    if (chdir(args[1]) < 0)
    {
        perror("Path error");
        done[0]=':';
        done[1]='(';
        return 1;
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
}
