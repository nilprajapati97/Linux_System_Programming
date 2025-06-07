#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr...\n");
}
main()
{
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=SA_RESETHAND;
		sigaction(2,&v,0);
		printf("hello..\n");
		while(1);
}

