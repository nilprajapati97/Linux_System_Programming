#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
int id;

id=msgget(2,IPC_CREAT|0644);
if(id<0)
{
perror("msgget");
return;

}
printf("id=%d\n",id);


}
