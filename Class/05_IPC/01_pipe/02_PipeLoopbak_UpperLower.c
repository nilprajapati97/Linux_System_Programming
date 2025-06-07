#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int p[2], q[2], i;

    // Create two pipes:
    // p: for parent to child communication
    // q: for child to parent communication
    pipe(p);
    pipe(q);

    if (fork() == 0)
    {
        // Child process
        char b[20];

        printf("In child before read...\n");

        // Read data from parent through pipe 'p'
        printf("in child -: Read data from parent through pipe 'p'\n");
        read(p[0], b, sizeof(b));

        // Convert to uppercase
        for (i = 0; b[i]; i++)
        {
            if (b[i] >= 'a' && b[i] <= 'z')
                b[i] = b[i] - 32;
        }

        // Send modified string back to parent through pipe 'q'
        printf("in child -: Send modified string back to parent through pipe 'q'\n");
        write(q[1], b, strlen(b) + 1);

        // Close used ends (optional but good practice)
        close(p[0]);
        close(q[1]);
    }
    else
    {
        // Parent process
        char a[20];

        printf("In parent, enter the data: ");
        scanf("%s", a);  // Read input string

        // Send the string to child via pipe 'p'
        printf("in parent -: Send the string to child via pipe 'p'\n");
        write(p[1], a, strlen(a) + 1);

        // Read the processed string back from child via pipe 'q'
        printf("in parent -: Read the processed string back from child via pipe 'q'\n");
        read(q[0], a, sizeof(a));

        printf("Data received from child (uppercase): %s\n", a);

        // Close used ends (optional)
        close(p[1]);
        close(q[0]);
    }

    return 0;
}
