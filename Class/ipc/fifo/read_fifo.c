#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{
	char a[20];
	int fd;

	mkfifo("f1",0666);
	perror("mkfifo");



	fd=open("f1",O_RDONLY);
	perror("open");
while(1)
{	
	read(fd,a,sizeof(a));
	if(a[0]=='\0')
	break;
	printf("data:%s\n",a);
	bzero(a,sizeof(a));
        
}
}
