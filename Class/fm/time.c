#include<stdio.h>
#include<time.h>

main()
{
time_t t1;


while(1)
{

time(&t1);
printf("%u\n",time(&t1));
//printf("%s\n",ctime(&t1));
sleep(1);
system("clear");
}
}
