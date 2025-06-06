#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>
main()
{
	int id,fd,fd1;

	char ch='A',ch1;

	struct sembuf v;

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
	fd1=open("data1",O_RDWR|O_APPEND|O_CREAT,0644);
	if(fd1<0)
	{
		perror("open");
		return;

	}

	v.sem_num=2;
	v.sem_op=0;
	v.sem_flg=0;

	for(ch='z',ch1='Z';ch>='a'&&ch1>='A'; ch--,ch1--)
	{

		semop(id,&v,1);
		semctl(id,1,SETVAL,1);
		semctl(id,2,SETVAL,1);

		write(fd1,&ch,1);
		write(fd1,&ch1,1);
		sleep(1);

		semctl(id,1,SETVAL,0);
	}	
	
	printf("done........\n");

}

