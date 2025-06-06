#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
main()
{
	int fd,fd1,i;
	int p[2];
	pipe(p);

	if(fork()==0)
	{ 
		char a[128];
		bzero(a,sizeof(a));
		printf("in the child ...\n");
		read(p[0],a,sizeof(a));
		for(i=0;a[i]; i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			a[i]=a[i]-32;		
		}
		fd=open("data2",O_WRONLY|O_CREAT|O_TRUNC,0644);
		write(fd,a,sizeof(a));

	}
	else
	{

		char s[128];
		bzero(s,sizeof(s));
		fd=open("data",O_RDONLY);
		if(fd<0)
		{
			perror("open");
			return;
		}

		read(fd,s,sizeof(s));
		printf("%s\n",s);
		write(p[1],s,sizeof(s));

	}

}
