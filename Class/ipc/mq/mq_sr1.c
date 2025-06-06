#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msgbuf
{
	long mtype;
	char data[30];

};
int id;
struct msgbuf v;
main(int argc,char** argv)
{

while(1)
{
	if(fork()==0)
	{
		
	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
	perror("msgget");
	return;
	}
	msgrcv(id,&v,sizeof(v),3,0);
	printf("data=%s\n",v.data);
	
	}
	else
	{/*

		if(argc!=2)
		{
			printf("usage:./a.out data\n");
			return;
		}
		*/

		id=msgget(5,IPC_CREAT|0644);
		if(id<0)
		{
			perror("msgget");
			return;
		}

		//printf("id=%d\n",id);

		v.mtype=2;
		//printf("enter the data\n");
		//strcpy(v.data,argv[2]);
		scanf("%s",v.data);
		msgsnd(id,&v,strlen(v.data)+1,0);
		perror("msgsnd");


	}


}

}
