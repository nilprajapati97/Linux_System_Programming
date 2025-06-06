#include<stdio.h>
main()
{
/*
//char *s="abcd";
printf("%d",2);
*/



int a=15,i,b=32;

for(i=31; i>=0; i--)
printf("%d",a>>i&1);
printf("\n");

a=(a>>b);
printf("%d\n",a);

for(i=31; i>=0; i--)
printf("%d",a>>i&1);
printf("\n");
printf("%d\n",a);
printf("\n");
}

