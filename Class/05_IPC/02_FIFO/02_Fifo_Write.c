#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
main()
{
	char a[20],b[20];
	int fd,fd1;

	mkfifo("f1",0666);
	mkfifo("f2",0666);


	fd=open("f1",O_WRONLY);
	fd1=open("f2",O_RDONLY);

	while(1)
	{
		printf("enter the data....\n");
		scanf("%s",a);
		write(fd,a,strlen(a)+1);
		read(fd1,b,strlen(b));
		printf("%s",b);


	} 

}
