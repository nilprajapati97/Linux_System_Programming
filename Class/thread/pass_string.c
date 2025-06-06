#include<stdio.h>
#include<pthread.h>
void *thread_1(void *p)
{
printf("in thread %s\n",(char *)p);
}

main()
{
pthread_t t1;

pthread_create(&t1,NULL,thread_1,"hello..");
while(1);

}

