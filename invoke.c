#include "header.h"
void printPrompt () 
{
    char* user = getenv("USER");
    char *curdir = (char *) malloc(1234*sizeof(char));

    char hostbuffer[256];
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    checkHostName(hostname);
    getcwd(curdir, 1234);
    char *s = curdir;
    host_entry = gethostbyname(hostbuffer);
    // checkHostEntry(host_entry);
    printf("\033[1;31m%s@", user);

    if (host_entry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    printf("\033[1;31m%s", hostbuffer);
    printf("\033[0m:");
    char *cwd[1000000];
    if (!(strncmp(curdir, root, strlen(root))))
    {
        *s++ = '~';
        int j = strlen(root);
        while(curdir[j]!='\0')
        {
            *s++ = curdir[j];
            j++;
        }
        *s = '\0';
    }
    printf("\033[1;32m%s", curdir);
        printf("\033[0m$ ");

    return;
}
