#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int pipe_fd[2];  // pipe_fd[0] for reading, pipe_fd[1] for writing

void *writer_thread(void *arg)
{
    char msg[100];
    while (1)
    {
        printf("Writer: Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        write(pipe_fd[1], msg, strlen(msg));
    }
    return NULL;
}

void *reader_thread(void *arg)
{
    char buffer[100];
    while (1)
    {
        ssize_t n = read(pipe_fd[0], buffer, sizeof(buffer) - 1);
        if (n > 0)
        {
            buffer[n] = '\0';  // Null-terminate
            printf("\nReader: Received -> %s", buffer);
        }
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Create pipe
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
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

    // Wait for threads (infinite loop in both threads)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
/*
Writer: Enter message: Anil
Writer: Enter message: 
Reader: Received -> Anil
Anil
Writer: Enter message: 
Reader: Received -> Anil
Prajapati
Writer: Enter message: 
Reader: Received -> Prajapati
ada
Writer: Enter message: 
Reader: Received -> ada
AnilPrajapati
Writer: Enter message: 
Reader: Received -> AnilPrajapati
^C



*/