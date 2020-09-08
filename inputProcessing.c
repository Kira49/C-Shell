#include"header.h"

char ** parseCommand(char *inp)
{
    char ** tokens = malloc(bufsize*sizeof(char *));
    if(!tokens)
    {
        memory_error();
    }
    ll pos=0;
    char *temp =strtok(inp,DELIM);
    while(1)
    {
        if(temp==NULL)
        {
            break;
        }
        tokens[pos]=temp;
        pos++;
        temp =strtok(NULL,DELIM);
    }
    tokens[pos]=NULL;
    return tokens;

}

char ** parseSemicolon()
{

    char *inp_string = NULL;
    getline(&inp_string,&bufsize,stdin);
    char ** tokens = malloc(bufsize*sizeof(char*));

    if(!tokens)
    {
        memory_error();
    }
    ll pos = 0;
    char *temp =strtok(inp_string,semi);
    while(1)
    {
        if(temp==NULL)
        {
            break;
        }
        tokens[pos]=temp;
        pos++;
        temp =strtok(NULL,semi);
    }
    tokens[pos]=NULL;
    return tokens;
}
