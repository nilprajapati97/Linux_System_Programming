#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	static int c,c1;
	if(n==SIGINT)
	{
		c++;
		if(c==3)
			signal(SIGINT,SIG_DFL);
	}
	if(n==SIGQUIT)
	{
		c1++;
		if(c1==1)
			signal(SIGQUIT,SIG_DFL);
	}
}
main()
{
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	while(1);
}
