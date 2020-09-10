#include"header.h"
// rhis is the very first file that is executed
int main(int arg1, char **arg2)
{
    // we initialise root
    getcwd(root, 1024);
    ll state;
		bg_arr=(char**)malloc(123456*sizeof(char *));
    while(1)
    {
	// invoke the funtion to prin t our prompt, wchich is written in invoke.c
        printPrompt();
        char **commands;
        char **argsi;
	int st;
	pid_t p;
        signal(SIGTSTP,ctrlZ);
        signal(SIGINT,ctrlC);
        bufsize = 0;
	// call function to take in and parse the commands separated by a semicolon
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
			// check if any of the previously executed background processes have completed
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
	  // call funtions to parse the commands futher, and then send then off for execution
          argsi = parseCommand(commands[i]);
          state=checkCommand(argsi);
        }
    }
    return EXIT_SUCCESS;
}
