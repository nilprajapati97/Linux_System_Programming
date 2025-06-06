#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int a[3];
main()
{
	if((a[0]=fork())==0)
	{
		int r;
		srand(getpid());
		r=rand()%10+1;
		printf("in c1 r=%d\n",r);
		sleep(r);
		exit(0);



	}
	else
	{
		if((a[1]=fork())==0)
		{
			int r;
			srand(getpid());
			r=rand()%10+1;
			printf("in c2 r=%d\n",r);
			sleep(r);
			exit(0);
		}
		else
		{
			if((a[2]=fork())==0)
			{
				int r;
				srand(getpid());
				r=rand()%10+1;
				printf("in c3 r=%d\n",r);
				sleep(r);
				exit(0);
			}
			else
			{
				int s,r;
				
				printf("a[0]=%d\n",a[0]);
				printf("a[1]=%d\n",a[1]);
				printf("a[2]=%d\n",a[2]);
				while((r=wait(0))!=-1)
				{
					s=s>>8;
					if(r==a[0])
						printf("c1\n");
				       else if(r==a[1])
						printf("c2\n");
					else if(r==a[2])
						printf("c3\n");
				}
			}
		}

	}

}
