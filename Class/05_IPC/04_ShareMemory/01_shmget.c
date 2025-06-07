#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int id;

    // Create a shared memory segment of size 50 bytes with key = 5
    id = shmget(5, 50, IPC_CREAT | 0666);
    if (id < 0) {
        perror("shmget failed");
        return 1;
    }

    printf("Shared Memory ID = %d\n", id);

    return 0;
}
