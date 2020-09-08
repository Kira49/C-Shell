#include"header.h"

ll PWD(char **args)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n",cwd );
    return 1;
}
