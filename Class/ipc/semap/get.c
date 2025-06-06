#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/sem.h>
main(int argc,char ** argv)
{
int ret;
int id;

if(argc!=2)
{
return(printf("Usage:./a.out semnum\n"));
}

id=semget(5,5,IPC_CREAT|0644);
if(id<0)
{
perror("shmget");
return;
}

printf("id=%d\n",id);


ret=semctl(id,atoi(argv[1]),GETVAL);
perror("semctl");
}
