#include"header.h"
int myunsetenv(char **args)
{
    if(args[1]==NULL)
    {
        perror("Inappropriate No of Args");
        return 0;
    }
    if(unsetenv(args[1])==-1) printf("setenv failed \n");
    return 1;
}
ll myjobs(char **args)
{
	ll j=0;
	char * s = "stopped";
	char * r = "running";
	int i=0;
	while(i<100005)
	{
        if(status[i]==0)
        {
            //chill
        }
        else
        {
                // printf("[");
                // printf("%lld",j++);
                // printf("]");
                if(bg_arr[i]!=NULL)
                {
                    printf("%d\n",i);
                    char * var2=(malloc(sizeof(char)*1005));
                    sprintf(var2,"/proc/%d/stat",i);
                    //pinfo wala same
                    FILE *f =fopen(var2,"r");
                    if(f==NULL)
                    {
                        perror("unable to open file \n");
                        return 0;
                    }
                    //first args
                    ll z=0;
                    int p;
                    char r[300];
                    char s;
                    char * str;
                    for(z=0;z<3;z++)
                    {
                        if(z==0)   fscanf(f,"%d",&p);
                        if(z==1)   fscanf(f,"%s",r);
                        if(z==2)   fscanf(f," %c",&s);
                    }
                    if(s=='R') status[i]=2;
                    if(s=='S') status[i]=2;
                    if(s!='S'&&s!='R') status[i]=1;
                    if(status[i]==1)   str="stopped";
                    else     str="running";
                    j++;
                    printf("[%lld]%s\t%s[%d]\n",j,str,bg_arr[i],i);
            }
			// if(status[i]!=1) printf("%s\t%s[%lld]\n",s,bg_arr[i],i);
			// else	printf("%s\t%s[%lld]\n",r,bg_arr[i],i);
		}
		i++;
	}
	return 1;
}
ll mykjobs(char **args)
{

    ll f=0;
    ll j=0,i=0,pid;
    ll x1= atoi(args[1]);
    while(i<1000005)
    {
        if(status[i]==0)
        {
            //chill
        }
        else
        {
            j++; //running jobs ++
            if(x1==j)
            {
                pid = i,f=1;
                break;
            }
        }
        i++;
    }
    ll x=atoi(args[2]);
    // printf("%lld%lld\n",x,pid );
    kill(pid,x);
    if(x==9) status[pid],bg_arr[pid]= NULL;
}
int mysetenv(char **args)
{
    if(args[1]==NULL)
    {
        perror("Inappropriate No of Args");
        return 0;
    }
    if(args[2]!=NULL&&args[3]!=NULL)
    {
        perror("Inappropriate No of Args");
        return 0;
    }
    else if(args[2]==NULL)
    {
        args[2]="";
    }

    if(setenv(args[1],args[2],1)==-1)    printf("setenv failed \n");

    return 1;
}

ll myfg(char ** args)
{
    ll j=1;
    ll i=0;
    ll x=atoi(args[1]);

    while(i<100005)
    {
        if(status[i]==0)
        {
            //chill
        }
        else
        {
            int s;
            if(j==x)
            {
                kill(i,SIGCONT);
                waitpid(i,&s,WUNTRACED);
                if(WIFEXITED(s))
                {
                    bg_arr[i]=NULL;
                    status[i] =0;
                }
                if(WIFSIGNALED(s))
                {
                    bg_arr[i]=NULL;
                    status[i] =0;
                }
                break;
            }
            else
            {
                j++;
            }

        }
        i++;
    }
}

ll mybg(char ** args)
{
    ll j=1;
    ll i=0;
    ll x=atoi(args[1]);

    while(i<100005)
    {
        if(status[i]==0)
        {
            //chill
        }
        else
        {
            int s;
            if(j==x)
            {
                kill(i,SIGCONT);
                status[i]=2;
                break;
            }
            else
            {
                j++;
            }

        }
        i++;
    }
}

ll myoverkill(char ** args)
{
    ll i=0,j=0;
    while(i<100005)
    {
        if(status[i]==0)
        {
            //chill
        }
        else j++,status[i]=0,bg_arr[i]=NULL,kill(i,9);
        i++;
    }
}
