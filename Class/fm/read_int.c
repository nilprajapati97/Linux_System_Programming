#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int fd,i;

	fd=open("dataint",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	read(fd,&i,sizeof(i));
	printf("%d\n",i);
}
