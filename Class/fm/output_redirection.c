#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
int fd;
close(1);

fd=open("data",O_WRONLY|O_TRUNC|O_CREAT,0644);

if(fd<0)
{
perror("open");
return;
}

printf("hello world....\n");
printf("fd=%d\n",fd);
}
