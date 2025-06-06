#include<stdio.h>
#include<signal.h>
main()
{
signal(SIGHUP,SIG_IGN);
printf("helloo...%d\n",getpid());
while(1);
}
