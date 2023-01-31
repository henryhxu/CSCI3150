/* example for using pipe() to communicate between parent and child process */

#include <assert.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h> /* perror */
#include <stdlib.h>
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h> /* fork, write */

int main() {
    pid_t pid;
    int wait_return, status;
    int pipe_fd[2];
    int bytes_read;
    int total_bytes_read = 0;
    char readbuf[1024];
    /* create a pipe */
    int ret = pipe(pipe_fd);
    if(ret < 0){
        perror("create pipe error\n");
        return 0;
    }
    pid = fork();
    if(pid == -1){
        perror("fork");
        assert(false);
    } 

    /* child process */
    else if(pid == 0){
        /* close un-unsed write end of the pipe */
        close(pipe_fd[1]);

        /* read from parent process into the buffer*/
        while ((bytes_read = read(pipe_fd[0], &readbuf[total_bytes_read], 1024-1-total_bytes_read)) > 0){
            total_bytes_read += bytes_read;
        }

        /* print the content in the buffer */
        readbuf[total_bytes_read]='\0';
        printf("[Message from parent] %s\n", readbuf);
        exit(0);
    }

    /* parent process */
    else{
        /* close un-used read end of the pipe */
        close(pipe_fd[0]);

        // sleep(5);
        /* write something into the pipe */
        write(pipe_fd[1], "Hello child process", 20);

        /* finished writing, close write end so child sees EOF */
        close(pipe_fd[1]);

        /* wait for the child process to terminate */
        while((wait_return = wait(&status)) > 0);
    }
    return 0;
}