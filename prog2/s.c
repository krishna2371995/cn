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
	mkfifo("p2",0666);
	int fid=open(argv[1],O_RDWR);
	char *buf=new char[size];
	while(1)
	{
		int n=read(fid,buf,size);
		if(n!=0)
		{
			for(int i=0;i<strlen(buf);i=i+4)
			{
				int sn=buf[i]-'0';
				char fifoname[1];
				fifoname[0]=buf[2];
				char *pn=new char[10];
				strcpy(pn,argv[sn]);
				strcat(pn,fifoname);
				int fd=open("file",O_RDWR);
				FILE *f=fdopen(fd,"r");
				f=popen(argv[sn],"r");
				char *buf2=new char[size];
				read(fd,buf2,size);
				printf("%s",buf2);
				fclose(f);	
			}
		}
	}
}
