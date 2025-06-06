#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
void my_isr(int n)
{
printf("in isr...%d\n",n);
//signal(n,SIG_IGN);
}
main()
{
printf("hello world....pid=%d\n",getpid());
//signal(2,my_isr);
signal(2,SIG_DFL);
printf("hai....\n");
pause();
printf("bye..\n");
//while(1);

}
