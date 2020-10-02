#include"header.h"
// this file contains out inbuilt ls command
// checking file permissons 
char const * filePerm(__mode_t mode) {
    static char local_buff[16];
    int i = 0;
    char r='r', w='w', x='x';
    for(int iter = 0; iter<16; iter++)
    {
        local_buff[iter] = '-';
    }
    // checking if it is a directory
    if (S_ISDIR(mode)) {
        local_buff[i] = 'd';
    }
    i++;
    // permissions for user
    if ((mode & S_IRUSR) == S_IRUSR) {
        local_buff[i] = r;
    }
    i++;
    if ((mode & S_IWUSR) == S_IWUSR) {
        local_buff[i] = w;
    }
    i++;
    if ((mode & S_IXUSR) == S_IXUSR) {
        local_buff[i] = x;
    }
    i++;
    // permissions for group
    if ((mode & S_IRGRP) == S_IRGRP) {
        local_buff[i] = r;
    }
    i++;
    if ((mode & S_IWGRP) == S_IWGRP) {
        local_buff[i] = w;
    }
    i++;
    if ((mode & S_IXGRP) == S_IXGRP) {
        local_buff[i] = x;
    }
    i++;
    // permissions for others
    if ((mode & S_IROTH) == S_IROTH) {
        local_buff[i] = r;
    }
    i++;
    if ((mode & S_IWOTH) == S_IWOTH) {
        local_buff[i] = w;
    }
    i++;
    if ((mode & S_IXOTH) == S_IXOTH) {
        local_buff[i] = x;
    }
    return local_buff;
}
// main
ll LS(char **args)
{
    // initialising flags
    bool flag=true, isdir=0, isexe=0;
    ll flagcheck=0, both=0;
    DIR *directory;
    char buf[1989],dir_name[1989];
    // setting flags after scanning arguments
    for(ll i=0;args[i]!=NULL;i++)
    {
        if(strcmp(args[i],"-a")==0)
        {
            flagcheck=1;
            both += 1;
        }
        if(strcmp(args[i],"-l")==0)
        {
            flagcheck=2;
            both += 1;
        }
        if(strcmp(args[i],"-la")==0||strcmp(args[i],"-al")==0)
        {
            flagcheck=3;
        }
        // if path of directory given
        if(args[i][0]=='~')
        {
            char *path=(char *) malloc(1234*sizeof(char));


            path=real_address(args,i);
            directory=opendir(path);
            if(directory!=NULL)
            {
                strcpy(dir_name,path);
                flag =false;
                continue;
            }
            else
            {
                fprintf(stderr,"ls: cannot access '%s': No such file or directory\n",path );
                return 1;
            }
        }
        if(args[i][0]=='-' && flagcheck==0 )
        {
            fprintf(stderr, "ls: flag does  not exist, printing current directory contents\n");
        }
    }
    // if path is true
    if(flag==true)
    {
        char cwd[1989];
        getcwd(cwd, sizeof(cwd));

        directory=opendir(cwd);
        if(directory!=NULL)
        {
            strcpy(dir_name,cwd);
        }
        else
        {
            fprintf(stderr,"ls: cannot access '%s': No such file or directory\n",cwd );
            return 1;
        }

    }
    // if both l and a flags are set
    if(flagcheck==3 || both>=2)
    {
        while(1)
        {
          if((dir = readdir(directory))== NULL)
          {
            break;
          }
            //stores on a string buffer instead of printing on console

            sprintf(buf, "%s/%s" , dir_name,dir->d_name);
            //we pass the file to read and read all its info using struct stat(here st)
            stat(buf,&st);
        

            //file type and mode
            char *ck = filePerm(st.st_mode);
            if(ck[0]=='d')
            {
              isdir = 1;
            }
            else if(ck[3]=='x')
            {
              isexe = 1;
            }
            
            printf("\033[0m%10.10s ", ck);

            printf("\033[0m%4lu",st.st_nlink );
            if ((password = getpwuid(st.st_uid)) == NULL)
            {
              printf(" %d", st.st_uid);
            }
            else {
              printf(" %s", password->pw_name);
            }
            if ((grp = getgrgid(st.st_gid)) == NULL) {
              printf(" %d", st.st_gid);
            }
            else {
              printf(" %s", grp->gr_name);
            }
            tm = localtime(&st.st_mtime);
            printf(" %9jd", (intmax_t)st.st_size);
            strftime(datestring, sizeof(datestring), "%b %d %H:%M", tm);
            printf(" %s ", datestring);
            if(isdir==1)
            {
                printf("\033[1;34m%s\n", dir->d_name);
                isdir = 0;
            }
            else if(isexe==1)
            {
                printf("\033[1;32m%s\n", dir->d_name);
                isexe = 0;
            }
            else
            {
                printf("\033[0m%s\n", dir->d_name);
            }
            printf("\033[0m");

        }
    }
    // if only l flag is set
    else if(flagcheck==2)
    {
        while(1)
        {
            if((dir = readdir(directory))== NULL)
            {
              break;
            }
            //stores on a string buffer instead of printing on console
            if(dir->d_name[0] == '.') continue;
            sprintf(buf, "%s/%s" , dir_name,dir->d_name);
            //we pass the file to read and read all its info using struct stat(here st)
            stat(buf,&st);

            //file type and mode
            char *ck = filePerm(st.st_mode);
            if(ck[0]=='d')
            {
              isdir = 1;
            }
            else if(ck[3]=='x')
            {
              isexe = 1;
            }
            printf("\033[0m%10.10s ", ck);

            printf("\033[0m%4lu",st.st_nlink );
            if ((password = getpwuid(st.st_uid)) == NULL)
            {
              printf(" %d", st.st_uid);
            }
            else {
              printf(" %s", password->pw_name);
            }
            if ((grp = getgrgid(st.st_gid)) == NULL) {
              printf(" %d", st.st_gid);
            }
            else {
              printf(" %s", grp->gr_name);
            }
            tm = localtime(&st.st_mtime);
            printf(" %9jd", (intmax_t)st.st_size);
            strftime(datestring, sizeof(datestring), "%b %d %H:%M", tm);
            printf(" %s ", datestring);
            if(isdir==1)
            {
                printf("\033[1;34m%s\n", dir->d_name);
                isdir = 0;
            }
            else if(isexe==1)
            {
                printf("\033[1;32m%s\n", dir->d_name);
                isexe = 0;
            }
            else
            {
                printf("\033[0m%s\n", dir->d_name);
            }
            printf("\033[0m");
        }
    }
    // if only a flag is set
    else if(flagcheck==1)
    {

        while(1)
        {
          if((dir = readdir(directory))== NULL)
          {
            break;
          }
            //stores on a string buffer instead of printing on console
            sprintf(buf, "%s/%s" , dir_name,dir->d_name);
            //we pass the file to read and read all its info using struct stat(here st)
            stat(buf,&st);
            //hidden files
            //file type and mode
            char *ck = filePerm(st.st_mode);
            if(ck[0]=='d')
            {
              isdir = 1;
            }
            else if(ck[3]=='x')
            {
              isexe = 1;
            }
            if(isdir==1)
            {
                printf("\033[1;34m%s\n", dir->d_name);
                isdir = 0;
            }
            else if(isexe==1)
            {
                printf("\033[1;32m%s\n", dir->d_name);
                isexe = 0;
            }
            else
            {
                printf("\033[0m%s\n", dir->d_name);
            }
            printf("\033[0m");

        }
        closedir(directory);
    }
    // no flags 
    else
    {
        //if no more items to read returns null
        while(1)
        {
            if((dir=readdir(directory))== NULL)
            {
              break;
            }
            sprintf(buf, "%s/%s" , dir_name,dir->d_name);

            stat(buf,&st);
            if(dir->d_name[0]=='.') continue;
            char *ck = filePerm(st.st_mode);
            if(ck[0]=='d')
            {
              isdir = 1;
            }
            else if(ck[3]=='x')
            {
              isexe = 1;
            }
            if(isdir==1)
            {
                printf("\033[1;34m%s\n", dir->d_name);
                isdir = 0;
            }
            else if(isexe==1)
            {
                printf("\033[1;32m%s\n", dir->d_name);
                isexe = 0;
            }
            else
            {
                printf("\033[0m%s\n", dir->d_name);
            }
            printf("\033[0m");

        }
        closedir(directory);
        printf("\n");
    }
}

