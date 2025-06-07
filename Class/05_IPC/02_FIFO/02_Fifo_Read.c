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


	fd=open("f1",O_RDONLY);
	fd1=open("f2",O_WRONLY);

	while(1)
	{
		read(fd,a,sizeof(a));
		printf("%s\n",a);
		printf("enter the data...\n");
		scanf("%s",b);
		write(fd1,b,strlen(b)+1);
	} 

}
