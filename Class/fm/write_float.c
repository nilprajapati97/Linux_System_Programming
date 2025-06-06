#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	float f=10.265;

	int fd;

	fd=open("dataint",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
		perror("open");
		return;
	}
	write(fd,&f,sizeof(f));


}
