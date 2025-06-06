#include<stdio.h>
void my_isr(int n)
{

printf("in isr..\n");
alarm(3);
}
main()
{
int ret;
signal(14,my_isr);
printf("hello...\n");
ret=alarm(15);
printf("ret=%d\n",ret);
printf("hai....\n");
sleep(3);
ret=alarm(2);
printf("ret=%d\n",ret);
while(1);
}
