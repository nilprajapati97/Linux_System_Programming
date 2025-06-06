#include<stdio.h>
main()
{
if(fork())
{
printf("in parent.pid=.%d ppid= %d\n",getpid(),getppid());
while(1);
}
else

{
printf("in child pid= %d ppid =%d\n",getpid(),getppid());
sleep(10);
printf("in child after sleep\n");

}

}
