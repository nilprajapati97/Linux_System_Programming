#include<stdio.h>
#include<pthread.h>
void *thread_1(void *p)
{
	printf("in thread %s\n",(char *)p);
	sleep(10);
	pthread_exit("bye");
}
main()
{
	char *p;
	pthread_t t1;

	pthread_create(&t1,NULL,thread_1,"hello");

	printf("before\n");
	pthread_join(t1,&p);

	printf("after...%s\n",p);

}

