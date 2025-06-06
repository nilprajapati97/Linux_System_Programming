#include<stdio.h>
void my_isr(int n)
{
printf("in isr.....\n");
}
main()
{
signal(14,my_isr);
printf("hello\n");
alarm(5);
printf("hai..\n");
while(1);

}
