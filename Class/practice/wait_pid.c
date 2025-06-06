#include<stdio.h>
main()
{
int i;
if((i=fork())==0)
{
printf("in c1...pid=%d",getpid());
printf("i=%d\n",i);
sleep(1);
exit(1);
}
else
{
int s,r;
printf("in parent before wiat pid...\n");
printf("i=%d\n",i);
r=waitpid(i,&s,0);
printf("after r= %u s=%u i=%u\n",r,s,i);

}


}
