#include <stdio.h>
#include <signal.h>
#include <unistd.h>  // For sleep()

// Custom signal handler function
void my_isr(int n) {
    printf("In ISR (Signal %d received)...\n", n);

    // Simulate long-running ISR with sleep
    sleep(10);

    printf("Exiting ISR after sleep...\n");
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, my_isr);

    printf("Hello... (Press Ctrl+C to trigger SIGINT)\n");

    // Keep the program running to wait for signals
    while (1);

    return 0;
}


/*
🧠 Explanation of Behavior
signal(SIGINT, my_isr);
    Registers your function my_isr() to handle SIGINT.
    So when you press Ctrl+C, it won’t terminate the program.
    Instead, it calls my_isr().

sleep(10);
    Introduces a delay inside the ISR to simulate a long task.
    During this sleep, if another signal (like another Ctrl+C) is received, it may be queued, ignored, or lost, depending on system behavior and whether signals are reentrant.

Infinite loop
    Keeps the main program running indefinitely so you can test the ISR.


Sample Output (if you press Ctrl+C twice quickly):
==================================================================
    Hello... (Press Ctrl+C to trigger SIGINT)
    ^CIn ISR (Signal 2 received)...
    [10 second pause...]
    Exiting ISR after sleep...

⚠️ Caution
====================================================
Using sleep() inside a signal handler is not recommended for production code, because:
    Many standard functions are not async-signal-safe.
    Can cause undefined behavior if reentrant signals are not handled properly.

Would you like an example using sigaction() with signal blocking to safely queue repeated signals?



✅ Problem with signal() + sleep() inside ISR
======================================================================
Using sleep() inside a signal()-based ISR is unsafe:
    -:  If the same signal arrives again during ISR execution, behavior is undefined.
    -:  You may lose the signal or crash the program.



✅ Solution: sigaction() + signal masking
Here’s how to safely handle signals using sigaction() and block the same signal during handler execution.


*/