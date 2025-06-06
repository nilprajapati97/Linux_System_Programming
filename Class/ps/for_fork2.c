#include<stdio.h>
main()
{
int i; 
printf("hello\n");

for(i=0; i<3; i++)
{
if(fork()==0)
{
printf("hai...\n");
}
else
break;
}
while(1);
}
