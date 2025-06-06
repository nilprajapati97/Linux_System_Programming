#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr...\n");
	sleep(10);
	printf("in isr affter slee\n");
}
main()
{
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=SA_NODEFER;
	sigaction(2,&v,0);
	while(1);

}

