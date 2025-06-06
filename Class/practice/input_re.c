#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,i;
int a[5];
close(0);
fd=open("data",O_RDONLY);
if(fd<0)
{
perror("open");
return;
}

for(i=0; i<5; i++)
scanf("%d",&a[i]);


for(i=0; i<5; i++)
printf("%d",a[i]);
printf("\n");
}
