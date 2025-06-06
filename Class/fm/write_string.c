#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	char s[]="vector india";

	int fd;

	fd=open("dataint",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
		perror("open");
		return;
	}
	write(fd,s,sizeof(s));


}
