#include<stdio.h>
main()
{
//int ret;
	if(fork()==0)
	{
		printf("1ret=%d\n",getpid());
		printf("1ppid=%d\n",getppid());

	}
	else
	{
		if(fork()==0)
		{
  			
		printf("2ret=%d\n",getpid());
		printf("2ppid=%d\n",getppid());

		}
		else
		{
			if(fork()==0)
			{

			
			printf("3ret=%d\n",getpid());
			printf("3ppid=%d\n",getppid());
			}
			else
			{
    
			printf("4ret=%d\n",getpid());
			printf("4ppid=%d\n",getppid());
				

			}

		}
	}
while(1);
}
