#include"header.h"


int main(int arg1, char **arg2) 
{
	bg_arr=(char**)malloc(123456*sizeof(char *));
    root = getenv("PWD");
    ll state;
    while(1) 
    {
        printPrompt();

        processflag=0;
        char **commands;
        char **argsi;
        commands=Psemicolon();    
        for (ll i=0; i>=0 ;i++)
        {   
        	if(commands[i]==NULL)
        	{
        		break;
        	}
        	int st;
        	pid_t p = waitpid(-1,&st,WNOHANG);
        	if(p > 0 && WIFEXITED(st)>0)
        	{
        		fprintf(stderr, "Process %s with pid: %d exited normally\n",bg_arr[p],p);
        		status[p]=0;
        		bg_arr[p]=NULL;
        	}
        	else if(p > 0 && WIFSIGNALED(st) == 1)
        	{
        		fprintf(stderr, "Process %s with pid: %d exited abnormally\n",bg_arr[p],p);
        	}

            
            argsi = readandparse(commands[i]);
            state=checkandrun(argsi);
        }
    }
    return EXIT_SUCCESS;
}	