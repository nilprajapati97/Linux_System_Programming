#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
main()
{
	char a[2];
	int fd;

	mkfifo("f1",0666);
	perror("mkfio");
	
	fd=open("f1",O_WRONLY);
	
while(1)
{
	printf("enter the data...\n");
	scanf("%s",a);
	if(a[0]!='\0')
	write(fd,a,strlen(a)+1);
	
}
}
