#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr...\n");
}
main()
{
	if(fork()==0)
	{
		printf("in child pid =%d\n",getpid());
		while(1);
	}else
	{
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=SA_NOCLDSTOP;
		sigaction(SIGCHLD,&v,NULL);
		while(1);
	}
}
