#include<stdio.h>
#include<stdlib.h>
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
int s,r;
printf("in paraent before wait pid....\n");
r=waitpid(-1,&s,0);
printf("after r=%u s=%u\n",r,s);
}

}





