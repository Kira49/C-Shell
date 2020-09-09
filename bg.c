#include "header.h"
ll BG(char **args)
{
    bool bg=false;
    int st;
    ll i=0;
    while(args[i]!=NULL)
    {
        if(strcmp(args[i],"&")==0)
        {
					if(args[i+1]==NULL)
					{
						bg=true;
						args[i]=NULL;
						break;
					}
        }
        i++;
    }

    pid_t pid=fork();


    if (pid < 0)
    {
        perror("ERROR:");
        return 1;
    }
    else if(pid==0)
    {
    	if(bg==true&&strcmp(args[0],"vi")==0)
			{
				exit(EXIT_SUCCESS);
			}
      if ( execvp(args[0], args) < 0)
      {
          fprintf(stderr,"command: %s not found, press Enter to continue\n",args[0] );
          exit(EXIT_FAILURE);
      }
    	return 0;
    }

    if(bg==false)
    {
			bg_arr[pid]=args[0];
			curr_pid = pid;
    	signal(SIGTSTP,ctrlZ2);
      pid_t wpid = waitpid (pid, &st, WUNTRACED);
    }
    else
    {
			bg_arr[pid]=args[0];
    	if(!(strcmp(args[0],"vi")))
			{
				status[pid]=1;
			}
    	else
			{
				status[pid]=2;
			}
    }
    return 1;
}
