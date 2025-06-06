#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr....\n");
	wait(0);
}
main()
{
	if(fork()==0)
	{
		printf("in child\n");
		sleep(5);
		printf("in child after sleep....\n");
	}
	else
	{
		signal(SIGCHLD,my_isr);
		printf("in  parent....\n");
		while(1);

	}
}


