#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>
main(int argc ,char ** argv)
{
	struct sembuf v;
	int id;


	id= semget(5,5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return;
	}

	v.sem_num=2;
	v.sem_op=0;
	v.sem_flg=0;


	printf("before...\n");
	semop(id,&v,1);
	printf("after....\n");
	sleep(15);
	printf("done...\n");

}
