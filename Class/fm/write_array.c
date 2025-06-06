#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	char a[]={10,20,30,40,50};

	int fd;

	fd=open("dataint",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
		perror("open");
		return;
	}
	write(fd,&a,sizeof(a));


}
