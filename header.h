#ifndef HEADER_H
#define HEADER_H
// header file. ntohing much to look at, just declaing globals and funtions and including necessary libraries
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
char done[2];
struct dirent *dir;
struct stat st;
ll status[1000005];
struct passwd *password;
struct group *grp;
ll LS(char **args);
struct tm *tm;
char datestring[1050];
char **bg_arr;
#define semi ";"
ll curr_pid;
char root[1024];
ll pos;
char prev[1024];
void checkHostName(int hostname);
bool found;
char ** parseCommand(char *inp);
char ** parseSemicolon();
char **bg_arr;
ll execute(char ** args);
ll checkCommand(char ** args);
void ctrlC(int signum);
void mainloop(void);
void printPrompt() ;
ll CD(char **args);
char *real_address(char ** args,ll st);
char* returnPath (char* cwd);
ll ECHO(char **args);
ll PWD(char **args);
ll BG(char **args);
int gbnum;
int mysetenv(char **args);
ll PINFO(char **args) ;
ssize_t bufsize;
char hist[20][1000];
int hist_i;
void ctrlZ(int signum);
void ctrlZ2();
ll quit(char ** args);
int redirect(char **args, int num);
void piping(char **args);
int myunsetenv(char **args);
ll myjobs(char **args);
ll mykjobs(char **args);
ll myfg(char ** args);
void memory_error();
int main(int a,char **b);



#endif
