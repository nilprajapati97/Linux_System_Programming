#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "f1"
#define FIFO2 "f2"

void *thread_1(void *arg)
{
    char a[100];
    int fd;

    printf("In thread T1: Opening %s for writing...\n", FIFO1);

    // Open as RDWR to avoid blocking
    fd = open(FIFO1, O_RDWR);
    if (fd < 0)
    {
        perror("open f1");
        pthread_exit(NULL);
    }

    while (1)
    {
        printf("T1: Enter message: ");
        scanf("%s", a);
        write(fd, a, strlen(a) + 1);
    }

    close(fd);
    return NULL;
}

void *thread_2(void *arg)
{
    char b[100];
    int fd;

    printf("In thread T2: Opening %s for reading...\n", FIFO2);

    // Open as RDWR to avoid blocking
    fd = open(FIFO2, O_RDWR);
    if (fd < 0)
    {
        perror("open f2");
        pthread_exit(NULL);
    }

    while (1)
    {
        ssize_t n = read(fd, b, sizeof(b));
        if (n > 0)
        {
            printf("T2: Received message: %s\n", b);
        }
    }

    close(fd);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Create FIFOs if they don't exist
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    // Create threads
    pthread_create(&t1, NULL, thread_1, NULL);
    pthread_create(&t2, NULL, thread_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
