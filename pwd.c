#include"header.h"
ll PWD(char **args)
{
    done[0]=':';
    done[1]=')';
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n",cwd );
    return 1;
}
