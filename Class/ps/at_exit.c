#include<stdio.h>
#include<stdlib.h>
void abc(void)
{
printf("in abc\n");

}
main()
{
atexit(abc);
printf("in main...\n");
sleep(10);
exit(0);

}

