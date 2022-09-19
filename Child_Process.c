// required header files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Write a program to create a child process such that the child should show the output of ls command. The child should finish before the parent process.

// main function
int main()
{
    int rc = fork(); // fork returns 0(for child process), -ve(if forking failed) and +ve(for parent process)
    if (rc < 0)      // if fork() failed to create child process return error
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) // child process
    {
        printf("This is the child process (PID: %d).\n", (int)getpid());
        printf("Output of 'ls' command: \n\n");
        system("ls"); // run the 'ls' command in the terminal
        printf("\n");
    }
    else // parent process
    {
        wait(NULL); // system call that won't return until child process has run and exited
        printf("This is the parent process (PID: %d) of child process (PID: %d).\n", (int)getpid(), rc);
    }
    return 0;
}