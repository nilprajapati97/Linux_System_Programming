#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>
main()
{
	int id,fd;

	char ch='a';

	struct sembuf v[2];

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

	v[0].sem_num=1;
	v[0].sem_op=0;
	v[0].sem_flg=0;

	
	v[1].sem_num=2;
	v[1].sem_op=0;
	v[1].sem_flg=0;

	for(ch='a';ch<='z'; ch++)
	{

		semop(id,&v,2);
		semctl(id,2,SETVAL,1);
		semctl(id,1,SETVAL,1);

		write(fd,&ch,1);
		write(fd,)
		sleep(1);

		semctl(id,2,SETVAL,0);
	}	
	
	printf("done........\n");

}

