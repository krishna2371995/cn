#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<poll.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define size 1024
typedef struct pollfd plfd;
int main(int argc,char **argv)
{
	mkfifo("p2",0666);
	int fid=open("p2",O_RDWR);
	char *buf=new char[size];
	printf("mss\n");
	plfd *pfd=new plfd;
	pfd[0].fd=fid;
	pfd[0].events=POLLIN;
	while(1)
	{
		int no=poll(pfd,1,0);
		if(no==1)
		{
			if(pfd[0].revents&POLLIN)
			{
				int n=read(fid,buf,size);
				printf("n is %d",n);
				int len=strlen(buf);
				printf("%d length",len);
				for(int i=0;i<strlen(buf);i=i+4)
				{
					int sn=buf[i]-'0';
					char fifoname[1];
					fifoname[0]=buf[2];
					char *pn=new char[10];
					strcpy(pn,argv[sn]);
					strcat(pn," ");
					strcat(pn,fifoname);
					printf("%s",pn);
					int fd=open("file",O_RDWR);
					FILE *f=fdopen(fd,"r");
					f=popen(pn,"r");
					char *buf2=new char[size];
					read(fd,buf2,size);
					printf("%s",buf2);
					fclose(f);	
				}
			}
		}
	}
}
