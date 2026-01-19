/* example for writing to a pipe with all of the file descriptors referring to the read-end closed */

#include <assert.h>
#include <signal.h>
#include <stdio.h> /* perror */
#include <stdlib.h>
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h> /* fork, write */

void signal_handler(int sig) {
    char s1[] = "SIGPIPE captured\n";
    char s2[] = "Unknown Signal\n";
    if (sig == SIGPIPE){
        write(STDOUT_FILENO, s1, sizeof(s1));
    } 
    else{
        write(STDOUT_FILENO, s2, sizeof(s2));
    }
}

int main() {
    pid_t pid = getpid();
    int pipe_fd[2];

    /* create a pipe */
    int ret = pipe(pipe_fd);
    if(ret < 0){
        printf("create pipe error\n");
        return 0;
    }

    /* create a singnal handler to capture signal pipe */
    signal(SIGPIPE, signal_handler);

    /* close all read end of the pipe */
    close(pipe_fd[0]);

    /* writer something to the pipe */
    write(pipe_fd[1], "test content", 12);
    return 0;
}
