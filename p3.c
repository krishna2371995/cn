#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#define size 1024
int main()
{
	char *buf=new char[size];
	while(1)
	{
		scanf("%s",buf);
		printf("%s",buf);
	}
}
