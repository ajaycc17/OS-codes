// required header files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Write a program consisting of three process (i.e, p, c1, c2), such that parent process, p crates a child, c1, and then c1 creates a child c2. In the program, p should exit/finish at the end and c2 should exit before the c1. The program output should print the exit order. (Hint: The exit order can be traced from the process pids)

// main function
int main()
{
    printf("Parent process P(PID: %d) created.\n", (int)getpid());
    int rc = fork(); // fork returns 0(for child process), -ve(if forking failed) and +ve(for parent process)
    if (rc < 0)      // if fork() failed to create child process return error
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) // child process C1
    {
        printf("Child process C1(PID: %d) created.\n", (int)getpid());
        int rc1 = fork(); // C1 creates its child process C2
        if (rc1 < 0)
        {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
        else if (rc1 == 0) // child process C2
        {
            printf("Child process C2(PID: %d) created.\n\n", (int)getpid());
            printf("Child process C2(PID: %d) exited.\n", (int)getpid());
        }
        else // Child process C1 and Parent of C2
        {
            wait(NULL);
            printf("Child process C1(PID: %d) exited.\n", (int)getpid());
        }
    }
    else // parent process
    {
        wait(NULL); // system call that won't return until child process has run and exited
        printf("Parent process P(PID: %d) exited.\n", (int)getpid());
    }
    return 0;
}