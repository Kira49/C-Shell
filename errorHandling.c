#include"header.h"
void checkHostName(int hostname)
{
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}
ll quit(char ** args)
{
    exit(EXIT_SUCCESS);
    return 0;
}
void memory_error()
{
	fprintf(stderr, "malloc error\n" );
        exit(EXIT_FAILURE);
}
void ctrlC(int signum)
{
    fprintf(stdout,"\nKeyboard interupt ^C, press enter to continue" );
    fflush(stdout);
		return;
}
void ctrlZ(int signum)
{
	return 	;
}
void ctrlZ2()
{
	return;
}
