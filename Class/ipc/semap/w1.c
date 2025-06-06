#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	struct sembuf v;
	int id ,i,fd;

	char a[]="abcdefghijklmno";

	id=semget(5,5,IPC_CREAT|0644);

	fd=open("data",O_RDWR|O_CREAT|O_APPEND,0644);

	v.sem_num =1;
	v.sem_op=0;
	v.sem_flg=0;

	printf("before...\n");
	semop(id,&v,1);
	printf("aftre...\n");
	semctl(id,1,SETVAL,1);

	for(i=0; a[i]; i++)
	{
		write(fd,&a[i],1);
		sleep(1);

	}

	semctl(id,1,SETVAL,0);
	printf("done....\n");

}
