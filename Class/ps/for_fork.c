#include<stdio.h>
main()
{

	int i;

	for(i=0; i<3; i++)
	{
		if(fork()==0)
			printf("hi\n");
		else
			;

	}
}
