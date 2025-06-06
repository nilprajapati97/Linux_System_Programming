#include<stdio.h>
main()
{
if(fork()==0)
{
printf("in child pid= %d ppid= %d \n ",getpid(),getppid());
sleep(10);
printf("in child pid =%d ppid =%d\n",getpid(),getppid());
while(1);

}
else
{
printf("in parent...\n");

sleep(5);
printf("after sleep in parent...\n");

}
}
