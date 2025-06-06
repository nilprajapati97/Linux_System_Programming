#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
struct st
{
	int rollno;
	char name[128];
	float marks;
};

main()
{
typedef struct st ST;

	ST s1={10,"abcd",22.66};
	int fd;

	fd=open("dataint",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
	perror("open");
	}
	
	write(fd,&s1,sizeof(ST));
}
