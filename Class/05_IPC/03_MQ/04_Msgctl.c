#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int msgid;
    struct msqid_ds info;

    // Create or get a message queue with key = 1234
    msgid = msgget(5, IPC_CREAT | 0644);
    if (msgid < 0) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue ID = %d\n", msgid);

    // Get message queue status
    if (msgctl(msgid, IPC_STAT, &info) == -1) {
        perror("msgctl - IPC_STAT");
        return 1;
    }

    // Print some info from the queue
    printf("\n--- Message Queue Info ---\n");
    printf("Last msg sent time : %ld\n", info.msg_stime);
    printf("Last msg recv time : %ld\n", info.msg_rtime);
    printf("Last change time   : %ld\n", info.msg_ctime);
    printf("Current # of bytes : %lu\n", info.__msg_cbytes);
    printf("Current # of msgs  : %lu\n", info.msg_qnum);
    printf("Max bytes allowed  : %lu\n", info.msg_qbytes);
    printf("PID of last send   : %d\n", info.msg_lspid);
    printf("PID of last recv   : %d\n", info.msg_lrpid);

    // Optional: remove the message queue
    // Uncomment to remove
    /*
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl - IPC_RMID");
        return 1;
    } else {
        printf("Message queue removed.\n");
    }
    */

    return 0;
}
