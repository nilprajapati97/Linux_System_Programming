#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

int main(int argc, char **argv)
{
    int sem_id;
    int sem_val;
    int sem_num;

    if (argc != 2)
    {
        printf("Usage: ./a.out <semnum>\n");
        return 1;
    }

    sem_num = atoi(argv[1]);

    // Create a semaphore set with 5 semaphores
    sem_id = semget(5, 5, IPC_CREAT | 0644);
    if (sem_id < 0)
    {
        perror("semget");
        return 1;
    }

    printf("Semaphore set ID = %d\n", sem_id);

    // Get the value of the specified semaphore
    sem_val = semctl(sem_id, sem_num, GETVAL);
    if (sem_val < 0)
    {
        perror("semctl");
        return 1;
    }

    printf("Semaphore %d value = %d\n", sem_num, sem_val);

    return 0;
}
