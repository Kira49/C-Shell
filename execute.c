#include"header.h"
// in this file we check the parsed command and redirect it to be executed by the appropriate function
ll checkCommand(char ** args)
{
	notfound=0;
	// if no command is found
	if(args[0]==NULL)
	{
		return EXIT_FAILURE;
	}
	if(strcmp(args[0],"quit")==0)
        {
    		return quit(args);
        }
	if(strcmp(args[0],"cd")==0)
	{
		return CD(args);
	}
	if(strcmp(args[0],"pwd")==0)
	{
		return PWD(args);
	}
	if(strcmp(args[0],"echo")==0)
	{
		return ECHO(args);
	}
	if(strcmp(args[0],"ls")==0)
	{
       		return LS(args);
	}
        if(strcmp(args[0],"pinfo")==0)
  	{
        	return PINFO(args);
  	}
	// if the command isnt any of the inbuilt ones, we send it to be checked for background process and be executed
  	if(notfound==0)
  	{
		return BG(args);
  	}
}
