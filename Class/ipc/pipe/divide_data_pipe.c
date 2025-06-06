#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int p[2];
	pipe(p);

	if(fork()==0)
	{
		char a1[6];
		read(p[0],a1,5);
		a1[5]='\0';

		printf("In child 1 : %s\n",a1);


	}
	else
	{
		if(fork()==0)
		{
			char a2[6];
			read(p[0],a2,5);
			a2[5]='\0';

			printf("In child 2 : %s\n",a2);


		}
		else
		{

			char s[128];

			printf("Enter 10 bytes of data : ");
			scanf("%s",s);

			if(strlen(s)>10)
			{
			printf("Length is grether then 10 bytes\n");
			return 0;
			}		
			printf("size is %d\n",strlen(s));
			write(p[1],s,sizeof(s));	
		}


	}


}
