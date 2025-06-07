#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>

int main() {
    int id;
    char *p;

    // Create or get a shared memory segment with key = 5 and size = 50 bytes
    id = shmget(5, 50, IPC_CREAT | 0666);
    if (id < 0) {
        perror("shmget");
        return 1;
    }

    printf("Shared Memory ID = %d\n", id);

    // Attach the shared memory segment to the process
    p = (char *)shmat(id, NULL, 0);
    if (p == (char *)(-1)) {
        perror("shmat");
        return 1;
    }

    // Loop to continuously write data into shared memory
    //while (1) {
        printf("Enter the data: ");
        scanf("%s", p);  // Data written directly to shared memory
        printf("Data written directly to shared memory\n");
        //}

    // (Unreachable in this case, but good practice to include)
    shmdt(p);  // Detach the shared memory

    return 0;
}
