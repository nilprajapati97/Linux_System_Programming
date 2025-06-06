#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>
main()
{
	struct sembuf v;
	char ch;
	int id,fd;
	id=semget(5,5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("semget");
		return;
	}
	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0644);
	if(fd<0)
	{
		perror("open");
		return;
	}
	v.sem_num=2;
	v.sem_op=0;
	v.sem_flg=0;
	for(ch='A';ch<='Z';ch++)
	{
		semop(id,&v,1);
		semctl(id,2,SETVAL,1);
		semctl(id,3,SETVAL,1);
		semctl(id,1,SETVAL,1);
		write(fd,&ch,1);
		sleep(1);
		
		semctl(id,3,SETVAL,0);
	}
printf("done...\n");
}
