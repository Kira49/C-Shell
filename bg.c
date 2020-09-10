#include "header.h"
// in this file, we wheck the user input to see if a background process is expected, and try to execute the background and foreground processes.
// if bg not expected, we execute the command normallyboth bg and fg despite being named as bg for convenience 
// this file contains 
ll BG(char **args)
{
    bool bg=false;
    int st;
    ll i=0;
    // checkinf if bg expected	
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
    //forking to create a child process. hereon, these lines of code are executed twice
    pid_t pid=fork();

    // error handling
    if (pid < 0)
    {
        perror("ERROR:");
        return 1;
    }
    else if(pid==0)
    {
	// vi command is an execption to our background processes since it causes issues. running vi & on terminal exits process
    	if(bg==true&&strcmp(args[0],"vi")==0)
			{
				exit(EXIT_SUCCESS);
			}
	// checking and executing commands
      if ( execvp(args[0], args) < 0)
      {
          fprintf(stderr,"command: %s not found, press Enter to continue\n",args[0] );
          exit(EXIT_FAILURE);
      }
    	return 0;
    }
    //waiting for process to complete if it isnt mentioned as background
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
    }
    return 1;
}
