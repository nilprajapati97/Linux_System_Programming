#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char data[100];

    // Open FIFO for writing
    mkfifo("myfifo ",0644);
    perror("mkfifo");
    
    printf("Before ..... %d\n",getpid());

    fd = open("myfifo", O_WRONLY);

    printf("After..... %d\n", getpid());

    printf("Enter data to write: ");
    scanf("%s",data);

    // Write data to FIFO
    write(fd, data, strlen(data) + 1);

    close(fd); // Close FIFO
    return 0;
}