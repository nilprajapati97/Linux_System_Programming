#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main()
{
    int p[2];  // p[0] is the read end, p[1] is the write end of the pipe

    // Create the pipe
    if (pipe(p) < 0)
    {
        perror("pipe");
        return;
    }

    // Print file descriptors for debugging
    printf("read end p[0] -: %d\nwrite end p[1] -: %d\n", p[0], p[1]);

    if (fork() == 0)
    {
        // Child process
        char b[20];  // Buffer to read data from pipe

        printf("\nIn child before read...\n");

        // Read from the read end of the pipe
        read(p[0], b, sizeof(b));

        // Display what was read
        printf("Child received: %s\n", b);

        // Close the read end (good practice)
        close(p[0]);
    }
    else
    {
        // Parent process
        char a[20];  // Buffer to write data into pipe

        printf("In parent, enter the data: ");
        
        // Take input from user
        scanf("%s", a);

        // Write the input string to the pipe (including null terminator)
        write(p[1], a, strlen(a) + 1);

        // Print what was written
        printf("Parent sent: %s\n", a);

        // Close the write end (good practice)
        close(p[1]);
    }
}



/*
output
--------------------------------------
read end p[0] -: 3
write end p[1] -: 4
In parent, enter the data: 
In child before read...
Anil_Prajapati
Parent sent: Anil_Prajapati
Child received: Anil_Prajapati


Note -: pipe is empty than read is blocked.
        pipe is full than write is blocked.

*/
