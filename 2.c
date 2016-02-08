#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/stat.h>
#define S1 "/mysem"
#define S2 "mysem2"
int main()
{
	sem_t *s1,*s2;
	s1=sem_open(S1,0);
	s2=sem_open(S2,0);
	int id1=shmget(1234,sizeof(int),0666|IPC_CREAT);
	int id2=shmget(2345,sizeof(int),0666|IPC_CREAT);
	int *buffer1=(int *)shmat(id1,0,0);
	int *buffer2=(int *)shmat(id2,0,0);
	int i=0;
	while(i<10)
	{
		sem_wait(s1);
		int k=*buffer1;
		*buffer2=k+1;
		printf("x is %d\n",*buffer2);
		sem_post(s2);
		i++;
	}

}
