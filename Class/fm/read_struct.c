#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
struct st
{
int no;
char name[128];
float marks;

};

main()
{
typedef struct st ST;

ST s1;	
int fd;
	fd=open("dataint",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	read(fd,&s1,sizeof(ST));
	printf("%d %s %f\n",s1.no,s1.name,s1.marks);
}
