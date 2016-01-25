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
	int rt=open(argv[1],O_RDWR);
	char *buf=new char[size];
	while(1)
	{
		scanf("%s",buf);
		int n=write(rt,buf,strlen(buf));
	}
}
