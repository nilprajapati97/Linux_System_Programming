#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
main()
{
struct rlimit v;
printf("hellllpoo.\n");

getrlimit(RLIMIT_CORE,&v);
printf("soft limit=%u\n hardlimit =%u\n",v.rlim_cur,v.rlim_max);

v.rlim_cur=0;
setrlimit(RLIMIT_CORE,&v);

printf("vector...\n");
while(1);
}
