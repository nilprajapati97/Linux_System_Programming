#include<stdio.h>
#include<pthread.h>
void *thread_1(void *p)
{
	while(1)
		printf("in thread_1...\n");
}

void *thread_2(void *p)
{
	while(1)
		printf("in thread_2...\n ");
}

main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);

	while(1);

}
