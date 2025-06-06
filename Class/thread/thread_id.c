#include<stdio.h>
#include<pthread.h>
void * thread_1(void *p)
{
	printf("in pthread_1 %u\n",pthread_self());

}

main()
{
	pthread_t t1;

	pthread_create(&t1,NULL,thread_1,NULL);
	printf("in main...t1=%u\n",t1);
	while(1);

}
