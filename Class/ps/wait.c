#include<stdio.h>
#include<stdlib.h>
//#include<sys/types.h>
#include<sys/wait.h>
main()
{
if(fork()==0)
{
printf("in child..pid=%d\n",getpid());
sleep(10);
exit(0);

}
else
{
int r,s;

printf("in parent...\n");
r=wait(&s);
printf("in parent after wait  s=%d r=%d\n",s,r);
r=wait(0);
printf("r=%d\n",r);

}
}
