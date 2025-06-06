#include<stdio.h>
main()
{
int ret;
ret=fork();
printf("%d\n",ret);
printf("hai\n");
while(1);

}
