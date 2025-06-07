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

    fd = open(FIFO1, O_WRONLY);
    if (fd < 0)
    {
        perror("open f1");
        pthread_exit(NULL);
    }

    while (1)
    {
        printf("T1: Enter message to send: ");
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

    fd = open(FIFO2, O_RDONLY);
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

    // Start writer thread
    if (pthread_create(&t1, NULL, thread_1, NULL) != 0)
    {
        perror("pthread_create T1");
        exit(EXIT_FAILURE);
    }

    // Start reader thread
    if (pthread_create(&t2, NULL, thread_2, NULL) != 0)
    {
        perror("pthread_create T2");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to complete (they won't unless program is interrupted)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
