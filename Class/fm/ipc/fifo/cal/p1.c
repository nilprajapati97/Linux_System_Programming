#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
struct st
{
	int a;
	char ch;
	int b;
};
main()
{

	
	struct st s1;
	int fd,fd1,s;
	
	mkfifo("f1",0666);
	perror("mkfifo");
	mkfifo("f2",0666);
	perror("mkfifo");

	fd=open("f1",O_WRONLY);
	perror("open fd");
	fd1=open("f2",O_RDONLY);
	perror("open fd1");

	printf("enter the first oprand..\n");
	scanf("%d",&s1.a);
	printf("enter the oprator..\n");
	scanf(" %c",&s1.ch);
	printf("enter the second oprand..\n");
	scanf("%d",&s1.b);

	write(fd,&s1,sizeof(s1));
	read(fd1,&s,sizeof(s));

	printf("total is=%d\n",s);

}
