#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>
main()
{
int id;

id=semget(5,5,IPC_CREAT|0644);
if(id<0)
{
perror("semget");
return;
}

printf("%d\n",id);

}
