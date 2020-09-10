#include"header.h"

//pinfo 
ll PINFO(char **args)
{
      char *str = (char*)malloc(1234*sizeof(char));
      int pid = getpid();
      if(args[1]!=NULL)
      {
        if (strcmp(args[1],"&")==0)
        {
          if(args[2]!=NULL)
            pid = atoi(args[2]);
          else
          {
            printf("invalid argument\n");
            return 1;
          }
        }
        else
            pid = atoi(args[1]);
      }
      if (!pid)
      {
          printf("invalid PID\n");
          return 1;
      }
      if(kill(pid,0))
      {
          perror("Invalid PID");
          return 1;
      }

      char bufff[100];
      
      printf("pid -- %d\n", pid);
      sprintf(str ,"/proc/%d/status",pid);

      FILE* file = fopen(str, "r");
      if (file == NULL)
      {
          perror("File Opening");
          return 1;
      }

      int count = 1;
      while (fgets(bufff, sizeof(bufff), file))
      {
          if(count == 3 )
          {
              // Process Status
              printf("Process %s",bufff);
              count++;
              continue;
          }
          if (count==18)
          {
              printf("%s",bufff);
              break;
          }
          count++;

      }


      sprintf(str ,"/proc/%d/exe",pid);
      char *path = (char*)malloc(1234*sizeof(char));

      readlink(str , path , 1000);
      printf("Executable Path -- %s\n", path);

      fclose(file);
      return 1;
}
