#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in my_isr...\n");

}
main()
{
	printf("hello world...pid =%d\n",getpid());
	signal(2,my_isr);
	printf("hai....\n");
	pause();
	printf("bye...\n");

}
