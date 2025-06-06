#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
main()
{
int id;

id=shmget(5,50,IPC_CREAT|0666);
if(id<0)
{
perror("shmget");
return;
}
printf("id=%d\n",id);

}
