#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid = 0;
    int status;
    int wait_return;

    for(int i=0; i<10; i++){
        /* create 10 child processes in parent process */
        if(pid == 0){
            pid = fork();
            if(pid < 0){
                printf("fork() failed\n");
                exit(-1);
            }
        }
    }

    if(pid > 0){
        printf("Hello from child %d\n",pid);
        exit(0);
    }
    
    /* wait for all child to terminate by checking the return value of wait */
    while((wait_return = wait(&status)) > 0){;}

    printf("All child terminated\n");

    return 0;
}