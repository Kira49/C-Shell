#include"header.h"
void piping(char **args)
{
	ll i=0,pipes=0;
	while(1)
	{
		if(args[i]==NULL)
		{
			break;
		}
		if(strcmp(args[i],"|")!=0)
		{
			i++;
			continue;
		}
		pipes++;
		i++;
	}
	ll j=0,finish=0, cnt=0, sz=i,frd;
	i=0;
	char *cur_com[1000];
	while(args[i]!=NULL && finish!=1)
	{
		ll p=0;
		while(finish!=1)
		{
			if(args[j]==NULL)
			{
				finish=1;
				continue;
			}
			if(strcmp(args[j],"|")==0)
			{
				break;
			}
			else
			{
				cur_com[p]=args[j];
				p++;
			}
			j++;
		}
		cur_com[p]=NULL;
		cnt++, j++;
		int fd[2], in,out;
		if(cnt==1)
		{
			if(pipe(fd)<0)
			{
				perror("Piping error:");
				return;
			}
			ll z=0;
			char infile[1000];
			while(1)
			{
				if(cur_com[z]==NULL)
				{
					break;
				}
				if(strcmp(cur_com[z],"<")==0)
				{
					in=dup(0);
					strcpy(infile,cur_com[z+1]);
			   		frd = open(infile,O_RDONLY, 0644);
					cur_com[z]=NULL;
					dup2(frd,0);
				}
				z++;
			}
			out=dup(1);
			dup2(fd[1],1);
			close(fd[1]);
		}
		if(finish==1 && cnt!=1)
		{
			char outfile[1000];
			ll z=0;
			while(1)
			{
				if(cur_com[z]==NULL)
				{
					break;
				}
				if(strcmp(cur_com[z],">")==0 || strcmp(cur_com[z],">>")==0)
				{
					out=dup(1);
					strcpy(outfile,cur_com[z+1]);
					frd= open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
					cur_com[z]=NULL;
					dup2(frd,1);
					close(frd);
				}
				z++;
			}
			in = dup(0);
			dup2(fd[0],0);
			close(fd[0]);
		}
		if(finish!=1 && cnt!=1)
		{
			in = dup(0), dup2(fd[0],0);
			if(pipe(fd)<0)
			{
				perror("Piping error :");
				return;
			}
			out=dup(1), dup2(fd[1],1);
			close(fd[1]);
		}
		pid_t pid;
		pid=fork();

		if(pid<0)
		{
			perror("Fork error : ");
			return;
		}
		if(pid==0)
		{
			if(execvp(cur_com[0],cur_com)<0)
			{
				perror("Command not found");
				exit(EXIT_FAILURE);
			}
		}
		if(pid>0)
		{
			wait(NULL);
			dup2(in,0);
			dup2(out,1);
		}

	}
}
