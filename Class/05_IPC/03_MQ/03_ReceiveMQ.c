#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

// Define the message buffer structure
struct msgbuf {
    long mtype;
    char data[20];
};

int main(int argc, char **argv) {
    int id;
    struct msgbuf v;

    // Validate argument count
    if (argc != 2) {
        printf("Usage: ./rcv <type>\n");
        return 1;
    }

    // Access or create the message queue with key = 5
    id = msgget(5, IPC_CREAT | 0644);
    if (id < 0) {
        perror("msgget");
        return 1;
    }

    // Receive message of specified type (from argv[1])
    long type = atol(argv[1]);  // Convert type to long
    if (msgrcv(id, &v, sizeof(v.data), type, IPC_NOWAIT) == -1) {
        perror("msgrcv");
        return 1;
    }

    printf("Received message of type %ld: %s\n", v.mtype, v.data);

    return 0;
}


/*
🧪 How to Run:
==========================================
/RCV 10
Received message of type 10: ANil



./Send 9 Anil_Prajapati
Message Queue ID = 3
Message sent successfully: type=9, data=Anil_Prajapati


./Receive 9
Received message of type 9: Anil_Prajapati


./Receive 9
msgrcv: No message of desired typ*/