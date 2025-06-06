#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int fd;
	char s[20];

	fd=open("dataint",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	read(fd,s,sizeof(s));
	printf("%s\n",s);
}
