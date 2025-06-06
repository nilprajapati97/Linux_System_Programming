#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
main(int argc,char **argv)
{
	struct stat v;
	struct dirent *p;
	DIR *dp;
	if(argc!=2)
	{
		printf("usage:./a.out dname\n");
		return;
	}

	dp=opendir(argv[1]);
	if(dp==0)
	{
		perror("opendir");
		return;
	}

	while(p=readdir(dp))
          { 
		if(p->d_name[0]!='.')
		{	
		printf("%s\n",p->d_name);
//		stat(p->d_name,&v);
//		perror("stat");
		}

	  }

}
