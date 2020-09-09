#include"header.h"

ll checkCommand(char ** args)
{
	ll cnt=0, notfound=0;

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
  if(notfound==0)
  {
		return BG(args);
  }
}
