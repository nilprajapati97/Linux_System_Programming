#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
int fd;



fd=open("data2",O_WRONLY|O_CREAT|O_TRUNC,0644);
if(fd<0)
{
perror("open");
return;
}

printf("fd=%d\n",fd);
}
