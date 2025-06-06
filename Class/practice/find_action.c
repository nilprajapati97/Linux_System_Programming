#include<stdio.h>
#include<signal.h>
main()
{
	int num;
	void (*p)(int);

	signal(2,SIG_IGN);
	printf("enter the number...\n");

	scanf("%d",&num);

	p=signal(num,SIG_IGN);

	signal(num,p);

	if(p==SIG_DFL)
		printf("Default...\n");
	else if(p==SIG_IGN)
		printf("ignore...\n");
	else
		printf("my isr...\n");

}
