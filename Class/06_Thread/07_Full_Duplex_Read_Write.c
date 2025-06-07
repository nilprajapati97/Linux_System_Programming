#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_PATH "myfifo"

void *writer_thread(void *arg)
{
    int fd;
    char msg[100];

    fd = open(FIFO_PATH, O_WRONLY);
    if (fd < 0)
    {
        perror("Writer: open");
        pthread_exit(NULL);
    }

    while (1)
    {
        printf("Writer: Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        write(fd, msg, strlen(msg));
    }

    close(fd);
    return NULL;
}

void *reader_thread(void *arg)
{
    int fd;
    char buffer[100];

    fd = open(FIFO_PATH, O_RDONLY);
    if (fd < 0)
    {
        perror("Reader: open");
        pthread_exit(NULL);
    }

    while (1)
    {
        ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
        if (n > 0)
        {
            buffer[n] = '\0';  // Null-terminate
            printf("Reader: Received -> %s", buffer);
        }
    }

    close(fd);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Create FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1)
    {
        perror("mkfifo (ignore if already exists)");
    }

    // Create writer thread
    if (pthread_create(&t1, NULL, writer_thread, NULL) != 0)
    {
        perror("pthread_create writer");
        exit(EXIT_FAILURE);
    }

    // Create reader thread
    if (pthread_create(&t2, NULL, reader_thread, NULL) != 0)
    {
        perror("pthread_create reader");
        exit(EXIT_FAILURE);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
/*
Writer: Enter message: Anil
Writer: Enter message: Reader: Received -> Anil
Anil
Writer: Enter message: Reader: Received -> Anil
Prajapati
Writer: Enter message: Reader: Received -> Prajapati
^C


*/