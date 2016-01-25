#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<signal.h>
#define size 1024
int main(int argc,char **argv)
{
	mkfifo(argv[1],0666);
	int fd=open(argv[1],O_RDWR);
	FILE *f=fdopen(fd,"r");
	fscanf(fd,"%d",pid);
	kill(pid,SIGUSR1);
}
