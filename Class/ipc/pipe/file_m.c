#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
main()
{

	int fd,p[2];
	pipe(p);

	if(!fork())
	{
		char s1[128];
		int i;
		bzero(s1,128);

		read(p[0],s1,sizeof(s1));

		//puts(s1);

		for(i=0;s1[i];i++)
			if(s1[i]>='a' && s1[i]<='z')
				s1[i]-=32;

		fd=open("data2",O_CREAT|O_TRUNC|O_WRONLY,0644);
		write(fd,s1,sizeof(s1));
	//	close(fd);
	}
	else
	{
		char s[128];
		bzero(s,128);
		fd=open("data",O_RDONLY);

		read(fd,s,sizeof(s));

		//	puts(s);

		write(p[1],s,sizeof(s));
	//	close(fd);	

	}
}
