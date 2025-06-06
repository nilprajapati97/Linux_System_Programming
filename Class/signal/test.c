#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/types.h>
int
main(int argc,char *argv[])
{
pid_t tid;

tid=syscall(SYS_gettid);
printf("%d\n",tid);
while(1);
}
