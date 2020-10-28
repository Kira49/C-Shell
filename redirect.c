#include"header.h"

int redirect(char **args, int num)
{
	int f1=0,f2=0,f3=0;
	ll prein,preout;
	ll fd0, fd1;
    ll x=100000000000;
	char *cur_com[1000];
    char in[1000],out[1000];
	ll i=0;
    while(1)
    {
        if(args[i]==NULL)
        {
            break;
        }
        if(strcmp(args[i++],"<")==0)
        {
            f1=1;
        }
    }
	i=0;
    while(1)
    {
        if(args[i]==NULL)
        {
            break;
        }
        if(strcmp(args[i++],">")==0)
        {
            f2=1;
        }
    }
	i=0;
    while(1)
    {
        if(args[i]==NULL)
        {
            break;
        }
        if(strcmp(args[i++],">>")==0)
        {
            f3=1;
        }
    }
    i=0;
	if(f1!=0)
	{
		while(1)
		{
            if(args[i]==NULL)
            {
                break;
            }
			if(strcmp(args[i],"<")==0)
			{
				if(i-1>=x)
                {
                    strcpy(in,args[i+1]);
                    continue;
                }
                strcpy(in,args[i+1]);
                x=i-1;
			}
			i++;
		}
	}
	if(f2+f3!=0)
	{
		i=0;
		while(1)
		{
            if(args[i]==NULL)
            {
                break;
            }
			if(strcmp(args[i],">")==0)
			{
				if(i-1>=x)
                {
                    strcpy(out,args[i+1]);
                    continue;
                }
                strcpy(out,args[i+1]);
                x=i-1;
			}
            else if(strcmp(args[i],">>")==0)
            {
                if(i-1>=x)
                {
                    strcpy(out,args[i+1]);
                    continue;
                }
                strcpy(out,args[i+1]);
                x=i-1;
            }
			i++;
		}
	}
	args[x+1]=NULL;
	if(f1!=0)
	{
		struct stat chk;
		if(stat(in,&chk)<0)
		{
			perror("File does not exist\n");
			done[0]=':';
			done[1]='(';
		}
		prein=dup(0);
   		fd0 = open(in,O_RDONLY, 0644);
		dup2(fd0,0);
	}
	if(f2+f3!=0)
	{
		preout=dup(1);
		if(f2==0)
        {
            fd1 = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
        }
		else
        {
            fd1 = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
		if(dup2(fd1,1)==-1)
		{
			perror("dup2 failed");
			done[0]=':';
			done[1]='(';
			return 0;
		}
	}
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		close(fd1);
		perror("fork error : ");
		done[0]=':';
		done[1]='(';
		return 0;
	}
    else if(pid)
    {
        wait(NULL);
        dup2(prein,0);
        dup2(preout,1);
        // exit(EXIT_FAILURE);
    }
	else
	{
		if(execvp(args[0],args)<0)
		{
			perror("Command not found");
			done[0]=':';
			done[1]='(';
			exit(EXIT_FAILURE);
		}
		else
		{
			done[0]=':';
			done[1]=')';
		}
	}

}
