#include"header.h"
// in this file we handle echho command.
// not yet taken quotes and environment variables into consideration
ll ECHO(char **args)
{
    // if no input is given after echo
    if(args[1]==NULL)
    {
    	printf("\n");
    	return 1;
    }
    // printing all arguments given back to the terminal
    ll i=1;
    while(args[i]!=NULL)
    {
        printf("%s ",args[i] );
        i++;
    }
    printf("\n");    	
    return 1;
}
