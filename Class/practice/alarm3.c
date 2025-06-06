#include<stdio.h>
#include<signal.h>
int i=0;
void my_isr(int n)
{
	i--;
	if(i==0)
		raise(9);
	else
		alarm(i);

}
main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out seconds\n");
		return;
	}
	i=atoi(argv[1]);
	alarm(i);
	while(1);

}
