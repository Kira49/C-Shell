#include"header.h"
void piping(char **args)
{
	ll i=0,pipes=0;
	//counting number of pipes
	while(args[i]!=NULL)
	{
		if(strcmp(args[i],"|")==0)
		{
			pipes++;
		}
		i++;
	}
	ll sz=i;
	i=0;
	ll j=0,finish=0;
	ll cnt=0;
	char *cur_com[1000];
	ll frd;
	while(1)
	{
		if(args[i]==NULL)break;
		if(finish==1)break;
		ll p=0;
		while(1)
		{
			if(args[j]==NULL)
			{
				finish=1;
				break;
			}
			if(strcmp(args[j],"|")!=0)
			{
				cur_com[p]=args[j];
				// printf("%s\n",cur_com[p]);
				p++;
			}
			else break;
			if(args[j]==NULL)
			{
				finish=1;
				break;
			}
			j++;
		}
		cnt++;
		j++;
		cur_com[p]=NULL;
		ll z=0;
		int fd[2];
		int in,out;
		// printf("%lld\n",finish );
		if(cnt==1)
		{
			if(pipe(fd)==-1)
			{
				perror("piping error :");
				return;
			}
			ll z=0;
			char infile[1000];
			while(cur_com[z]!=NULL)
			{
				// printf("%s\n",cur_com[z] );
				if(strcmp(cur_com[z],"<")==0)
				{
					cur_com[z]=NULL;
					strcpy(infile,cur_com[z+1]);
					// ll zz=0;
					// while(cur_com[zz]!=NULL)
					// {
						// printf("%s\n",cur_com[zz] );
						// zz++;
					// }
					in=dup(0);
			   		frd = open(infile,O_RDONLY, 0644);
					dup2(frd,0);
				}
				z++;
			}
			out=dup(1);
			dup2(fd[1],1);
			close(fd[1]);
		}
		else if(finish==1)
		{
			// redirect
			ll z=0;
			char outfile[1000];
			ll flagg=0;
			while(cur_com[z]!=NULL)
			{
				// printf("%s\n",cur_com[z] );
				if(strcmp(cur_com[z],">")==0)
				{
					cur_com[z]=NULL;
					strcpy(outfile,cur_com[z+1]);
					out=dup(1);
					frd= open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
					dup2(frd,1);
					close(frd);
					flagg=1;
				}
				else if(strcmp(cur_com[z],">>")==0)
				{
					cur_com[z]=NULL;
					strcpy(outfile,cur_com[z+1]);
					out=dup(1);
					frd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
					dup2(frd,1);
					close(frd);
					flagg=1;
				}
				z++;
			}
			in = dup(0);
			dup2(fd[0],0);
			close(fd[0]);
		}
		else
		{
			in = dup(0);
			dup2(fd[0],0);
			if(pipe(fd)==-1)
			{
				perror("piping error :");
				return;
			}
			out=dup(1);
			dup2(fd[1],1);
			close(fd[1]);
		}
		pid_t pid;
		pid=fork();

		if(pid==-1)
		{
			perror("fork error : ");
			return;
		}
		else if(!pid)
		{
			if(execvp(cur_com[0],cur_com)==-1)
			{
				perror("command not found");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			dup2(in,0);
			dup2(out,1);
		}

	}
}
