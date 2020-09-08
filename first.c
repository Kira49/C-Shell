#include"header.h"


int main(int arg1, char **arg2)
{
    getcwd(root, 1024);
    ll state;
    while(1)
    {
        printPrompt();

        char **commands;
        char **argsi;
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
          bufsize = 100005;
          argsi = parseCommand(commands[i]);
          state=checkCommand(argsi);
        }
    }
    return EXIT_SUCCESS;
}
