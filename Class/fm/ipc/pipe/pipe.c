#include<stdio.h>
#include<string.h>
#include<unistd.h>
main()
{
	int p[2],q[2],i;
	pipe(p);
	pipe(q);

	if(fork()==0)
	{
		char b[20];
		printf("in child before read...\n");
		read(p[0],b,sizeof(b));

		for(i=0; b[i]; i++)
		{
			if(b[i]>='a'&&b[i]<='z')
				b[i]=b[i]-32;
		}
		write(q[1],b,strlen(b)+1);
	}
	else
	{
		char a[20];
		printf("in parent enter the data...\n");
		scanf("%s",a);
		write(p[1],a,strlen(a)+1);
		read(q[0],a,strlen(a)+1);
		printf("data=%s\n",a);
	}

}
