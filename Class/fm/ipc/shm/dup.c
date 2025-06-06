#include<stdio.h>
#include<sys/unistd.h>
main()
{
	int fd;
	fd=dup(1);

	write(fd,"hello\n",6);

}
