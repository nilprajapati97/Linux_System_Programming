#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
int fd;

printf("pid=%d\n",getpid());

fd=open("data",O_RDONLY);
if(fd<0)
{
perror("open");
return;
}


}
