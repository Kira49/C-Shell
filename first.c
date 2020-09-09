#include"header.h"

int main(int arg1, char **arg2)
{
    getcwd(root, 1024);
    ll state;
		bg_arr=(char**)malloc(123456*sizeof(char *));
    while(1)
    {
        printPrompt();
        char **commands;
        char **argsi;
				int st;
				pid_t p;
        signal(SIGTSTP,ctrlZ);
        signal(SIGINT,ctrlC);
        bufsize = 0;
        commands=parseSemicolon();
        for (ll i=0; i>=0 ;i++)
        {
        	if(commands[i]==NULL)
        	{
        		break;
        	}
        	p = waitpid(-1,&st,WNOHANG);
					if(p>0)
					{
						if(WIFEXITED(st)>0)
						{
							fprintf(stderr, "Process %s with pid-- %d has exited normally\n",bg_arr[p],p);
							bg_arr[p]=NULL;
						}
						else if(WIFSIGNALED(st))
						{
							fprintf(stderr, "Process %s with pid-- %d has exited abnormally\n",bg_arr[p],p);
						}
					}
          bufsize = 100005;
          argsi = parseCommand(commands[i]);
          state=checkCommand(argsi);
        }
    }
    return EXIT_SUCCESS;
}
