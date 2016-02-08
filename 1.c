#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<fcntl.h>
#include<sys/stat.h>
#define S1 "/mysem"
#define S2 "/mysem2"
int main()
{
	sem_t *s1,*s2;
	s1=sem_open(S1,O_CREAT,0644,0);
	s2=sem_open(S2,O_CREAT,0644,0);
	int id1=shmget(1234,sizeof(int),0666|IPC_CREAT);
	int id2=shmget(2345,sizeof(int),0666|IPC_CREAT);
	int *buffer1,*buffer2;
	buffer1=(int *)shmat(id1,0,0);
	buffer2=(int *)shmat(id2,0,0);
	int x=1;
	*buffer1=x;
	sem_post(s1);
	int i=0;
	while(i<10)
	{
		sem_wait(s2);
		x=*buffer2;
		*buffer1=x+1;
		printf("y is %d\n",*buffer1);
		sem_post(s1);
		i++;
	}
	/*sem_close(s1);
	sem_close(s2);
	sem_unlink(S1);
	sem_unlink(S2);*/
}
