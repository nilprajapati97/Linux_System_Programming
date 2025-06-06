#include<stdio.h>
#include<unistd.h>
main()
{
int i=10;

if(fork()==0)
{
printf("in child i=%d\n",i);
}
else
{
i=20;
printf("in parent i=%d\n",i);
}


}
