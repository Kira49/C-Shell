#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
#include <grp.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#define DELIM " \t\n\a\r"
#define ll long long int


#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)

struct dirent *dir;
struct stat st;
ll status[1000005];
struct passwd *password;
struct group *grp;
ll LS(char **args);
struct tm *tm;
char datestring[1050];
#define semi ";"
char root[1024];
ll pos;
void checkHostName(int hostname);
char ** parseCommand(char *inp);
char ** parseSemicolon();

ll execute(char ** args);
ll checkCommand(char ** args);
void ctrlC(int signum);
void mainloop(void);
void printPrompt() ;
char ** breakem(char * a);
ll CD(char **args);
char *actual_address2(char ** args,ll st);
char* returnPath (char* cwd);
ll ECHO(char **args);
ll PWD(char **args);

ll PINFO(char **args) ;
ssize_t bufsize;

void ctrlZ(int signum);
ll quit(char ** args);
void memory_error();
int main(int a,char **b);
