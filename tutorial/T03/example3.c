#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid;
    pid = fork();
    if(pid == -1){
        printf("Fork error\n");
        exit(-1);
    }
    else if(pid > 0){
        /* parent */
        printf("parent is doing something\n");
        sleep(5);
        printf("parent finished its task");
    }
    else{
        /* child */
        execlp("ls","ls","-a",NULL);
    }
    return 0;
}