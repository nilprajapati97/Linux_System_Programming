#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{

printf("in isr...\n");
sleep(10);
printf("in isr after sleep...\n");

}
main()
{
printf("hello world pid =%d\n",getpid());
signal(2,my_isr);
printf("'hai...\n");
while(1);


}
