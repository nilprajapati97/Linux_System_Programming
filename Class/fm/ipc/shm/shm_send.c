#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
main()
{
	int id;
	char *p;

	id=shmget(5,50,IPC_CREAT|0666);
	if(id<0)
	{
		perror("shmget");
		return;
	}

	printf("id=%d\n",id);
	p=shmat(id,0,0);

	printf("enter the data...\n");
	scanf("%s",p);


}
