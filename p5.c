#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#define size 1024
int main(int argc,char **argv)
{
	mkfifo(argv[1],0666);
	int fd=open(argv[1],O_RDONLY);
	char *buf=new char[size];
	int n=read(fd,buf,strlen(buf));
	printf("from p5");
	printf("\n%s",buf);
}
