#include<stdio.h>
#include<unistd.h>
#include<limits.h>
void abc(void)
{
printf("in abc...\n");
}
main()
{
long l;
//atexit(abc);
//l=sysconf(_SC_ARG_MAX);
l=sysconf(_SC_CHILD_MAX);
printf("in main...%d\n",l);
sleep(5);
//atexit(abc);
}
