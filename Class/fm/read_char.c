#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int fd;
	char ch;

	fd=open("dataint",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	read(fd,&ch,sizeof(ch));
	printf("%c\n",ch);
}
