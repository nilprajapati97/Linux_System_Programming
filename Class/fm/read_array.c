#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int fd,i;
	char a[10];

	fd=open("dataint",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	read(fd,&a,sizeof(a));
	for(i=0; i<5; i++)
	printf("%d\n",a[i]);
}
