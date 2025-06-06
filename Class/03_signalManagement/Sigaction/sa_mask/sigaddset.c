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
	sigaddset(&v.sa_mask,3);
	v.sa_flags=0;
	sigaction(3,&v,0);
	while(1);

}
