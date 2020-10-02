#include"header.h"
// in this file we check the parsed command and redirect it to be executed by the appropriate function
ll checkCommand(char ** args)
{
	ll notfound=0;
	ll pip=0,red=0;
	ll i=0;
    while(1)
    {
		if(args[i]==NULL)
		{
			break;
		}
        if(strcmp(args[i],">")==0)
        {
            red=1;
        }
		if(strcmp(args[i],"<")==0)
		{
			red=1;
		}
		if(red==1)
		{
			break;
		}
        i++;
    }

    i=0;
    while(1)
    {
		if(args[i]==NULL)
		{
			break;
		}
        if(strcmp(args[i],"|")==0)
        {
            pip=1;
        }
		if(pip==1)
		{
			break;
		}
        i++;
    }
    if(pip)
    {
        piping(args);
        return 1;
    }
    if(red)
    {
        redirect(args,1);
        return 1;
    }
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
	if(strcmp(args[0],"setenv")==0)
    {
        return mysetenv(args);
    }
    if(strcmp(args[0],"unsetenv")==0)
    {
        return myunsetenv(args);
    }
    if(strcmp(args[0],"jobs")==0)
    {
        return myjobs(args);
    }
    if(strcmp(args[0],"kjob")==0)
    {
        return mykjobs(args);
    }
    if(strcmp(args[0],"overkill")==0)
   	{
   		return myoverkill(args);
   	}
    if(strcmp(args[0],"fg")==0)
    {
        return myfg(args);
    }
    if(strcmp(args[0],"bg")==0)
    {
        return mybg(args);
    }
	// if the command isnt any of the inbuilt ones, we send it to be checked for background process and be executed
  	if(notfound==0)
  	{
		return BG(args);
  	}
}
