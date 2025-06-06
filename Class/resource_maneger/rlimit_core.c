#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
main()
{
struct rlimit v;


getrlimit(RLIMIT_CORE,&v);
printf("soft limit =%u\n hard limit=%u\n",v.rlim_cur,v.rlim_max);

// =========to set limit  ======================//

v.rlim_cur=1000;
setrlimit(RLIMIT_CORE,&v);

//===================================================//


getrlimit(RLIMIT_CORE,&v);
printf("soft limit =%u\n hard limit=%u\n",v.rlim_cur,v.rlim_max);




}
