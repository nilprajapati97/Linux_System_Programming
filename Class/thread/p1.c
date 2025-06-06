#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>
void *thread_1(void *p)
{
	char a[20];
	int fd;

	fd=open("f1",O_RDWR);
	while(1)
	{
		scanf("%s",a);
		write(fd,a,strlen(a)+1);
	}
}
void *thread_2(void *p)
{
	char a[20];
	int fd;

	fd=open("f2",O_RDWR);
	while(1)
	{
		read(fd,a,sizeof(a));
		
		printf("data=%s\n",a);

	}

}
main()
{
	pthread_t t1,t2;

	mkfifo("f1",0644);
	mkfifo("f2",0644);

	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);

	while(1);


}
