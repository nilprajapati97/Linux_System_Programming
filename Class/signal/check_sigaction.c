#include<stdio.h>
#include<signal.h>
main()
{
	int num;
	struct sigaction v;
	signal(2,SIG_IGN);
	printf("enter the number...\n");
	scanf("%d",&num);

	sigaction(num,NULL,&v);

	if(v.sa_handler==SIG_DFL)
		printf("default...\n");
	else if(v.sa_handler==SIG_IGN)
		printf("ignore...\n");
	else
		printf("my isr......\n");
}
