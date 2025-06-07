#include <stdio.h>
#include <pthread.h>
#include <unistd.h>     // for sleep()
#include <string.h>
#include <stdlib.h>     // for exit()

void *thread_1(void *arg)
{
    printf("In thread T1... %s\n", (char *)arg);
    sleep(10);
    pthread_exit("bye");
}

int main()
{
    char *ret_val;
    pthread_t t1;

    // Create a new thread
    if (pthread_create(&t1, NULL, thread_1, "Hello") != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    printf("In main, t1 = %lu\n", t1);
    printf("Before pthread_join...\n");

    // Wait for the thread to finish
    if (pthread_join(t1, (void **)&ret_val) != 0)
    {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("After pthread_join... return value: %s\n", ret_val);

    return 0;
}
/*
output
======================

In main, t1 = 140213674968640
Before pthread_join...
In thread T1... Hello
After pthread_join... return value: bye


*/