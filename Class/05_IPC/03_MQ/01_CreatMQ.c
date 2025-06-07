#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int id;

    // Create or access a message queue with key = 2
    id = msgget(5, IPC_CREAT | 0644);

    if (id < 0) {
        perror("msgget failed");
        return 1;  // Return error status
    }

    printf("Message Queue ID = %d\n", id);

    return 0;
}
