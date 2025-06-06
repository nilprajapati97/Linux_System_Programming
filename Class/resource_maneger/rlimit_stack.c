#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
main()
{
struct rlimit v;
getrlimit(RLIMIT_STACK,&v);
printf("soft limit =%u\n hard limit =%u\n",v.rlim_cur,v.rlim_max);

// =====  to change limit====== //

v.rlim_cur=1000;
setrlimit(RLIMIT_STACK,&v);

//===============================//

getrlimit(RLIMIT_STACK,&v);
printf("soft limit =%u\n hard limit =%u\n",v.rlim_cur,v.rlim_max);

}
