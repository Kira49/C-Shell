#include"header.h"
ll ECHO(char **args)
{

    if(args[1]==NULL)
    {
    	printf("\n");
    	return 1;
    }

    ll i=1;
    while(args[i]!=NULL)
    {
        printf("%s ",args[i] );
        i++;
    }
    printf("\n");    	
    return 1;
}