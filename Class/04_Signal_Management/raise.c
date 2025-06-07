#include<stdio.h>
#include<signal.h>
main()
{
int i;
printf("hello..%d\n",getpid());
i=raise(19);
printf("%d\n",i);
}
