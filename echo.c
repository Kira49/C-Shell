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
    char a[1000];
    ll x= strlen(args[1]);
    ll i=1, isenv=0;
    // printf("%c\n",args[1][1] );
    if(args[1][0]=='$')
    {
        isenv = 1;
    }
    if(isenv==0)
    {
        i=1;
        // printing all arguments given back to the terminal
        while(args[i]!=NULL)
        {
            printf("%s ",args[i] );
            i++;
        }
        printf("\n");
        return 1;
    }
    else
    {
        for(i=0; i<x-1; i++)
        {
            a[i]=args[1][i+1];
        }
        a[x]='\0';
        if(getenv(a)==NULL)
        {
            perror("Not a env:");
            return 0;
        }
        printf("%s\n",getenv(a));
        return 1;
    }
}
