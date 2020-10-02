#include"header.h"
int myunsetenv(char **args)
{
    if(args[1]==NULL)
    {
        perror("Inappropriate number of arguments\n");
        done[0]=':';
        done[1]='(';
        return 0;
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
    if(unsetenv(args[1])<0)
    {
        printf("Setenv failed \n");
        done[0]=':';
        done[1]='(';
        return 1;
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
    return 1;
}
ll myjobs(char **args)
{
	ll j=0;
	int i=0;
    char * str;
    int p;
    char r[300], s;
	while(i<100005)
	{
        if(status[i]==0)
        {
            i++;
            continue;
        }
        else
        {
                if(bg_arr[i]==NULL)
                {
                    i++;
                    continue;
                }
                char * var2=(malloc(sizeof(char)*1007));
                sprintf(var2,"/proc/%d/stat",i);
                printf("%d\n",i);
                //pinfo wala same
                FILE *f =fopen(var2,"r");
                if(f==NULL)
                {
                    perror("Can't open file \n");
                    done[0]=':';
                    done[1]='(';
                    return 0;
                }
                else
                {
                    done[0]=':';
                    done[1]=')';
                }
                //first args
                ll z=0;
                fscanf(f,"%d",&p);
                fscanf(f,"%s",r);
                fscanf(f," %c",&s);
                if(s!='S'&&s!='R')
                {
                    status[i]=1;
                }
                else
                {
                    status[i]=2;
                }
                if(status[i]!=1)
                {
                    str="running";
                }
                else
                {
                    str="stopped";
                }
                j++;
                printf("[%lld]%s\t", j,str);
                printf("%s[%d]\n", bg_arr[i],i);
                i++;
		}
	}
	return 1;
}
ll mykjobs(char **args)
{
        ll j=0,i=0,pid;
        if(args[1]==NULL || args[2]==NULL)
        {
            perror("Inappropriate number of arguments\n");
            done[0]=':';
            done[1]='(';
            return 0;
        }
        else
        {
            done[0]=':';
            done[1]=')';
        }
        ll x1= atoi(args[1]);

        while(i<1000005)
        {
            if(status[i]==0)
            {
                i++;
                continue;
            }
            else
            {
                j++; //running jobs ++
                if(x1==j)
                {
                    pid = i;
                    break;
                }
                i++;
            }
        }
        ll x=atoi(args[2]);
        // printf("%lld%lld\n",x,pid );
        kill(pid,x);
        if(x==9) status[pid]=0;
}
int mysetenv(char **args)
{
    if(args[2]==NULL)
    {
        args[2]="";
    }
    if(args[1]==NULL || args[3]!=NULL)
    {
        perror("Inappropriate number of arguments");
        done[0]=':';
        done[1]='(';
        return 0;
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }

    if(setenv(args[1],args[2],1)<0)
    {
        perror("Setenv failed \n");
        done[0]=':';
        done[1]='(';
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
    return 1;
}

ll myfg(char ** args)
{
    done[0]=':';
    done[1]=')';
    ll x=atoi(args[1]);
    ll j=1, i=0;
    while(i<100005)
    {
        if(status[i]==0)
        {
            i++;
            continue;
        }
        int s;
        if(j==x)
        {
            kill(i,SIGCONT);
            waitpid(i,&s,WUNTRACED);
            if(WIFEXITED(s) || WIFSIGNALED(s))
            {
                status[i] =0;
                bg_arr[i]=NULL;
            }
            break;
        }
        j++;
        i++;
    }
}

ll mybg(char ** args)
{
    done[0]=':';
    done[1]=')';
    ll x=atoi(args[1]);
    ll j=1, i=0;
    while(i<100005)
    {
        if(status[i]==0)
        {
            i++;
            continue;
        }
        int s;
        if(j==x)
        {
            kill(i,SIGCONT);
            status[i]=2;
            break;
        }
        j++;
        i++;
    }
}

ll myoverkill(char ** args)
{
    done[0]=':';
    done[1]=')';
    ll i=0;
    while(i<100005)
    {
        if(status[i]!=0)
        {
            status[i]=0;
            kill(i,9);
        }
        i++;
    }
}
