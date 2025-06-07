
/*
struct sigaction {
    void     (*sa_handler)(int);    // Pointer to signal handler function (basic form)
    void     (*sa_sigaction)(int, siginfo_t *, void *); // Used with SA_SIGINFO
    sigset_t sa_mask;               // Signals to block during handler execution
    int      sa_flags;              // Modifies behavior (e.g., SA_RESTART, SA_SIGINFO)
    void     (*sa_restorer)(void);  // (Obsolete) - ignored on modern systems
};

sigaction(num, &v, NULL); 
               New action
sigaction(num, NULL, &v); 
                     old action
sigaction(num, &v, &v); 
               New and Old action
*/

#include <stdio.h>
#include <signal.h>

// Custom signal handler function
void my_isr(int n)
{
    printf("In ISR (Interrupt Service Routine)...\n");
}

int main()
{
    struct sigaction v;

    // Set the handler function for the signal
    //signal (2.my_isr);
    v.sa_handler = my_isr;

    // Initialize the signal mask to empty (no blocked signals during the handler execution)
    sigemptyset(&v.sa_mask);

    // No special flags
    v.sa_flags = 0;

    // Register the signal handler for signal 2 (SIGINT - usually Ctrl+C)
    sigaction(2, &v, 0);

    // Inform the user that the program is running
    printf("Hello....\n");

    // Infinite loop to keep the program running
    while (1);

    return 0;
}
