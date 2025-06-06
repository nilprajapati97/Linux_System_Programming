#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
main()
{
if(fork()==0)
{
printf("in c1...pid=%d\n",getpid());
sleep(10);
exit(1);
}
else
{
printf("in parent before wait pid...\n");
waitpid(-1,0,WNOHANG);

printf("hai...\n");

}

}
