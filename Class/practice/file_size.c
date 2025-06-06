#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc ,char** argv)
{

	struct stat v;
	if(argc!=2)
	{
		printf("usage:./a.out filename...\n");
		return;

	}

	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}


	printf("size=%d\n",v.st_size);


}
