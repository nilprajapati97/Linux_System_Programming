#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int i=10;

	int fd;

	fd=open("dataint",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
		perror("open");
		return;
	}
	write(fd,&i,sizeof(i));


}
