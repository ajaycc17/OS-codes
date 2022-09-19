#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    printf("\n");
    int rc = fork();
    printf("My rc and pid values are %d, %d\n",rc, getpid());
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("hello, I am child (pid:%d)", (int) getpid());
        printf("\n");
    } else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        printf("\n");
    }
    return 0;


}