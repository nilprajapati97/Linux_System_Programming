#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("in isr.....\n");
}
main()
{
	struct sigaction v;
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    signal(2, SIG_IGN);
	sigaction(num,NULL,&v);

	if(v.sa_handler==SIG_DFL)
        printf("Default.....\n");
    else if(v.sa_handler==SIG_IGN)
        printf("Ignore...\n");
    else
        printf("My_ISR......");
        
	while(1);
}
