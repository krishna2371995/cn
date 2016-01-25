#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<poll.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<string.h>
#define size 1024
typedef struct pollfd plfd;
int flag=0;
void handler(int sig)
{
	signal(SIGUSR1,handler);
	flag=1;	
}
int main(int argc,char **argv)
{
	signal(SIGUSR1,handler);
	mkfifo(argv[1],0666);//for p3 fifo
	mkfifo(argv[2],0666);//for 
	mkfifo(argv[3],0666);//to senfd pid
	int fd[3];
	for(int i=0;i<3;i++)
	{
		fd[i]=open(argv[i+1],O_RDWR);
	}
	int pd[2];
	pipe(pd);
	int pid=fork();
	if(pid!=0)
	{
		close(pd[1]);
		int spid=getpid();
		FILE *fp=fdopen(fd[2],"w");
		fprintf(fp,"%d",spid);
		FILE *f=popen(argv[4],"r");
		int pod=fileno(f);
		plfd *pfd=new plfd[4];
		pfd[0].fd=0;//kb
		pfd[1].fd=pd[0];//pipe
		pfd[2].fd=fd[2];//fifo
		pfd[3].fd=pod;//popen
		for(int i=0;i<4;i++)
		{
			pfd[i].events=POLLIN;
		}
		char *buf=new char[size];
		while(1)
		{
			int n=poll(pfd,4,0);
			if(n==1)
			{
				for(int i=0;i<4;i++)
				{
					if(pfd[i].revents&POLLIN)
					{
						if(flag==0)
						printf("%s",buf);
						else
						{
							write(fd[3],buf,strlen(buf));
						}
					}
				}
			}
		}
	}
	else
	{
		char *buf=new char[size];
		scanf("%s",buf);
		close(pd[0]);
		write(pd[1],buf,strlen(buf));				
	}
}
