#include<stdio.h>
main()
{
int ret;
printf("hello...\n");
ret=fork();

if(ret==0)
printf("in child...%d\n",getpid());
else
printf("in parent..ret=%d\n",ret);

printf("hai");
while(1);
}
