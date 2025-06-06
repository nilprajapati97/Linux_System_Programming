#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
main()
{
int fd;
char a[20];
char b[20]={'a','b'};

fd=open("data",O_RDONLY);

if(fd<0)
{
perror("open");
return;

}
bzero(a,sizeof(a));
//memset(a,'z',sizeof(a));

read(fd,a,5);
//memcpy(b,a,sizeof(a));
memmove(b,a,sizeof(a));
printf("data=%s\n",a);
printf("data=%s\n",b);

}
