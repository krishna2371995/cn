#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<poll.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define size 1024
int main(int argc,char **argv)
{
	char *buf=new char[size];
	mkfifo(argv[1],0666);
	int fd=open(argv[1],O_RDWR);
	while(1)
	{
		read(fd,buf,size);
		printf("%s",buf);
		printf("server reads\n");
	}
}
