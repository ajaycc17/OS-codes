#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    printf("\n");
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("hello, I am child (pid:%d)", (int) getpid());
        printf("\n");
    } else {
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
        printf("\n");
    }
    return 0;


}