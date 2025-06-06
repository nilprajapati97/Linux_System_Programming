#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
struct flock v;
char a[]="123456789";
int fd,i;
fd=open("data",O_RDWR|O_APPEND|O_CREAT,0666);


/////////////////////////////////////////////////////

v.l_type=F_WRLCK;
v.l_whence=SEEK_SET;
v.l_start=0;
v.l_len=0;

printf("before...\n");
fcntl(fd,F_SETLKW,&v);
printf("after....\n");

//////////////////////////////////////////////////////////////

for(i=0; a[i]; i++)
{
write(fd,&a[i],1);
sleep(1);

}

////////////////////////////////////////////////////////////////////

v.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&v);

printf("done....\n");
}

