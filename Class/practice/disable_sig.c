#include<stdio.h>
#include<signal.h>

void my_isr(int n)
{
printf("in my isr...\n");
signal(SIGINT,SIG_DFL);
signal(SIGQUIT,SIG_DFL);


}
main()
{
signal(SIGINT,SIG_IGN);
signal(SIGQUIT,SIG_IGN);
signal(SIGALRM,my_isr);
alarm(10);
while(1);
}
