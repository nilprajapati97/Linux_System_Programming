#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr...\n");
	signal(n,SIG_DFL);

}
main()
{
	printf("hello world..pid=%d\n",getpid());
	signal(SIGINT,SIG_IGN);
	printf("hai....\n");
	while(1);

}
