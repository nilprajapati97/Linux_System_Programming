/*
3. Observation program :
main()
{
		printf(“before %d and %d\n”,getpid(),getppid());
		fork();
		printf(“1: %d and %d\n”,getpid(),getppid());
		fork();
		printf(“2: %d and %d\n”,getpid(),getppid());
		fork();
		printf(“3: %d and %d\n”,getpid(),getppid());
}
*/
#include<stdio.h>
main()
{
		printf("before %d and %d\n",getpid(),getppid());
		fork();
		printf("1: %d and %d\n",getpid(),getppid());
		fork();
		printf("2: %d and %d\n",getpid(),getppid());
		fork();
		printf("3: %d and %d\n",getpid(),getppid());
while(1);
}

