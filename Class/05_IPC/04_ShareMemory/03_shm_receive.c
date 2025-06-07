#include <stdio.h>
#include <stdlib.h>      // For exit()
#include <unistd.h>      // For sleep()
#include <sys/types.h>
#include <sys/shm.h>

int main() {
    int id;
    char *p;

    // Create or get a shared memory segment with key 5 and size 50 bytes
    id = shmget(5, 50, IPC_CREAT | 0666);
    if (id < 0) {
        perror("shmget");  // Print error if shmget fails
        exit(1);
    }

    //while (1) {
        printf("Shared Memory ID = %d\n", id);

        // Attach the shared memory to process address space
        p = shmat(id, NULL, 0);
        if (p == (char *)-1) {
            perror("shmat");
            exit(1);
        }

        // Print the content from shared memory
        printf("Data from shared memory: %s\n", p);

        sleep(2);  // Sleep added to avoid spamming output
    //}

    return 0;
}
