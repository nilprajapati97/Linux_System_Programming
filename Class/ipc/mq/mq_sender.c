#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/types.h>
struct msgbuf
{

	long mtype;
	char data[20];
};
main(int argc,char **argv)
{
	int id;

	struct msgbuf v;

	if(argc!=3)
	{
		printf("usage:./send type data\n");
		return;
	}
	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return;
	}

	printf("id=%d\n",id);

	v.mtype=atoi(argv[1]);
	strcpy(v.data,argv[2]);

	msgsnd(id,&v,strlen(v.data)+1,0);
	perror("msgsnd");







}
