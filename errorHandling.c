#include"header.h"
// this file contains a few utility functions to handle errors and signals
// handles error while getting name of host
void checkHostName(int hostname)
{
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}
// helps you quit the terminal
ll quit(char ** args)
{
    exit(EXIT_SUCCESS);
    return 0;
}
// handles errors in memory allocation
void memory_error()
{
	fprintf(stderr, "malloc error\n" );
        exit(EXIT_FAILURE);
}
// handles ctrl C keyboard interrupt
void ctrlC(int signum)
{
    fprintf(stdout,"\nKeyboard interupt ^C, press enter to continue" );
    fflush(stdout);
		return;
}
// handle ctrl Z
void ctrlZ(int signum)
{
	return 	;
}
void ctrlZ2()
{
	return;
}
