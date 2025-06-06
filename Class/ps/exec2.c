#include<stdio.h>
#include<unistd.h>
main()
{
printf("pid =%d ppid =%d\n",getpid(),getppid());
execl("./p1","p1",NULL);

}
