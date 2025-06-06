#include<stdio.h>
#include<stdlib.h>
main()
{
float a[5];
int i;
srand(getpid());

 for(i=0; i<5; i++)
{
  a[i]=rand()%51+25;
	a[i]=a[i]/100;

}
for(i=0; i<5; i++)
printf("%f  ",a[i]);
printf("\n");


}
