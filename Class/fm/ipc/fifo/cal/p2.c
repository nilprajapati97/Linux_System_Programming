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
	mkfifo("f2",0666);


	fd=open("f1",O_RDONLY);
	fd1=open("f2",O_WRONLY);

	read(fd,&s1,sizeof(s1));

	if(s1.ch=='+')
	{
		s=s1.a+s1.b;
	}
	else
		printf("not data\n");

	write(fd1,&s,sizeof(s));
}
