#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct msgbuf
{
	long mtype;
	char data[20];

};
main(int argc,char **argv)
{
	int id;
	struct msgbuf v;

	if(argc!=2)
	{
		printf("usage:./rcv type\n");
		return;

	}

	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return;
	}

	msgrcv(id,&v,sizeof(v),0,IPC_NOWAIT);
	printf("data=%s\n",v.data);


}
