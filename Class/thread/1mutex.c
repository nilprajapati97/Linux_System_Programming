#include<stdio.h>
#include<pthread.h>
pthread_mutex_t m1,m2;
void *thread_1(void *p)
{
	char i;
	for(i='a';i<='z';i++)
	{
		pthread_mutex_lock(&m1);
		printf("%c\t",i);
		fflush(stdout);

		sleep(1);

			pthread_mutex_unlock(&m2);

	}

}

void* thread_2(void *p)
{
	char i;

	for(i='A';i<='Z'; i++)
	{
		pthread_mutex_lock(&m2);
		printf("%c\n",i);
		sleep(1);
		pthread_mutex_unlock(&m1);

	}

}

main()
{
	pthread_t t1,t2;

	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);
	pthread_mutex_lock(&m2);


	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);


	pthread_exit(0);
}

