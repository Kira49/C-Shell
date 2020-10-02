#include"header.h"
// parses command further
char ** parseCommand(char *inp)
{
    char ** tokens = malloc(bufsize*sizeof(char *));
    if(!tokens)
    {
        memory_error();
    }
    ll pos=0;
    // separated command by delimitors to separate command from argument
    char *temp =strtok(inp,DELIM);
    while(1)
    {
        if(temp==NULL)
        {
            break;
        }
        // stored
        tokens[pos]=temp;
        pos++;
        temp =strtok(NULL,DELIM);
    }
    tokens[pos]=NULL;
    return tokens;

}
// invoked to take in the user input and separate the commands by semicolon
char ** parseSemicolon()
{

    char *inp_string = NULL;
    getline(&inp_string,&bufsize,stdin);
    if(strlen(inp_string)<=0)
    {
        printf("\n");
        exit(0);

    }
    char ** tokens = malloc(bufsize*sizeof(char*));

    if(!tokens)
    {
        memory_error();
    }
    ll pos = 0;
    // separated by semicolon
    char *temp =strtok(inp_string,semi);
    while(1)
    {
        if(temp==NULL)
        {
            break;
        }
        // separated command stored
        tokens[pos]=temp;
        pos++;
        temp =strtok(NULL,semi);
    }
    tokens[pos]=NULL;
    return tokens;
}
