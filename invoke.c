#include "header.h"
// in this file we initialise the user and system name, and print the command prompt
void printPrompt ()
{
    char* user = getenv("USER");
    char *curdir = (char *) malloc(1234*sizeof(char));
    // a lot of searching for hostname which im still quite confused about phew. finally stored in host buffer
    char hostbuffer[256];
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    // checking for error
    checkHostName(hostname);
    //getting current directory
    getcwd(curdir, 1234);
    char *s = curdir;
    host_entry = gethostbyname(hostbuffer);
    // printing user in red
    printf("\033[1;31m%s", done);
    printf("\033[1;31m%s@", user);

    if (host_entry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
    else
    {
        done[0]=':';
        done[1]=')';
    }
    // printing system name in red
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
    // rpinting current directory
    printf("\033[1;32m%s", curdir);
        printf("\033[0m$ ");

    return;
}
