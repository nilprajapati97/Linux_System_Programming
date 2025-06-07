#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

int main(int argc, char **argv)
{
    int sem_id;
    int ret;
    int sem_num;
    int sem_val;

    if (argc != 3)
    {
        printf("Usage: ./a.out <semnum> <semvalue>\n");
        return 1;
    }

    sem_num = atoi(argv[1]);
    sem_val = atoi(argv[2]);

    // Create a semaphore set with 5 semaphores
    sem_id = semget(5, 5, IPC_CREAT | 0644);
    if (sem_id < 0)
    {
        perror("semget");
        return 1;
    }

    printf("Semaphore set ID = %d\n", sem_id);

    // Set the value of the specified semaphore
    ret = semctl(sem_id, sem_num, SETVAL, sem_val);
    if (ret < 0)
    {
        perror("semctl - SETVAL");
        return 1;
    }

    printf("Semaphore %d value set to %d\n", sem_num, sem_val);

    return 0;
}
