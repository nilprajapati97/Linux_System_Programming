#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
main()
{
	char ch='a';
	int p[2],c=0;

	pipe(p);
	fcntl(p[1],F_SETFL,O_NONBLOCK);

	while(write(p[1],&ch,1)!=-1)
	{
		c++;
	}
	printf("c=%d\n",c);
	printf("hai...\n");

}
