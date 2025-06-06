#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
main(int argc, char ** argv)
{
	struct stat v;
	if(argc!=2)
	{
		printf("usage:./a.out filename..\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;

	}
	if(S_ISREG(v.st_mode))
		printf("reguler file ...\n");
	else if(S_ISDIR(v.st_mode))
		printf("directory....\n");



}
