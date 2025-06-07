#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

// Define message buffer structure
struct msgbuf {
    long mtype;
    char data[20];
};

int main(int argc, char **argv) {
    int id;
    struct msgbuf v;

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./send <type> <data>\n");
        return 1;
    }

    // Create or get the message queue with key 5
    id = msgget(5, IPC_CREAT | 0644);
    if (id < 0) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue ID = %d\n", id);

    // Prepare message
    v.mtype = atoi(argv[1]);            // Convert string to long
    strcpy(v.data, argv[2]);            // Copy message content

    // Send message
    if (msgsnd(id, &v, strlen(v.data) + 1, 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully: type=%ld, data=%s\n", v.mtype, v.data);

    return 0;
}

/*
🧪 How to Run:
==========================================
./Send 10 ANil
Message Queue ID = 3
Message sent successfully: type=10, data=ANil



*/
