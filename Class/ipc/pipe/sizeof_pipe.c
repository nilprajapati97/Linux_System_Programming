#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	char ch='a';
	int p[2],c=0;

//	pipe(p);
	pipe2(p,O_NONBLOCK);
	while(write(p[1],&ch,1)!=-1)
	{
		c++;

	}
		printf("c=%d\n",c);
	printf("thanks...\n");

}
