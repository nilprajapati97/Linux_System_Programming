#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
main()
{
struct rlimit v;


getrlimit(RLIMIT_FSIZE,&v);
printf("soft limit =%u\n hard limit=%u\n",v.rlim_cur,v.rlim_max);

// =========to set limit  ======================//

v.rlim_cur=5;
setrlimit(RLIMIT_FSIZE,&v);

//===================================================//


getrlimit(RLIMIT_FSIZE,&v);
printf("soft limit =%u\n hard limit=%u\n",v.rlim_cur,v.rlim_max);

FILE *fp;
fp=fopen("data","w");
fwrite("abcdefgh",8,1,fp);


}
