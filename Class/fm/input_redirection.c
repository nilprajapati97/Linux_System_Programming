#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
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
for(i=0;i<5; i++)
scanf("%d\n",&a[i]);

for(i=0;i<5; i++)
printf("%d\n",a[i]);


}
