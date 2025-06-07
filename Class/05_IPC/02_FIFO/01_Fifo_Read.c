#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char data[100];

    // Open FIFO for writing
    mkfifo("myfifo",0644);
    perror("mkfifo");
    
    printf("Before ..... %d\n",getpid());

    fd = open("myfifo", O_RDONLY);

    printf("After..... %d\n", getpid());

    
    read(fd, data, sizeof(data));
    printf("Data =%s\n",data);

    close(fd); // Close FIFO
    return 0;
}