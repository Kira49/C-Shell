#include "header.h"
char* returnPath (char* cwd)
{
    ll cwd_size = strlen(cwd);
    ll root_size = strlen(root);
    if (root_size > cwd_size)
    {
        return cwd;
    }
    if (root_size == cwd_size)
    {
        return "~";
    }
    if(root_size < cwd_size)
    {
        char *new = (char*)malloc(100);
        new[0] = '~', new[1] = '/';
        for (ll i = 2; i <= cwd_size-root_size; i++)
        {
            new[i] = cwd[root_size+i-1];
        }
        return new;
    }
}
char *real_address(char ** args,ll st)
{
    char *newPath = (char *) malloc(1989*sizeof(char));
    if(!newPath)
    {
         memory_error();
    }
    strcpy(newPath,root);
    // newPath[0] = '~';
    ll len = strlen(args[st]);
    ll iter=strlen(root);
    for(int j=1; j<len; j++)
    {
        newPath[iter] = args[st][j];
        iter++;
    }
    newPath[iter]='\0';
    return newPath;

}
