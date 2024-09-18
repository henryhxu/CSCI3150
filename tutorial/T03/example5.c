/* example for using pipe() in one process */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int pipe_fd[2];
    int bytes_read;
    int total_bytes_read = 0;
    char readbuf[1024];
    /* create a pipe */
    int ret = pipe(pipe_fd);
    if(ret < 0){
        printf("create pipe error\n");
        return 0;
    }

    /* write something into the pipe */
    write(pipe_fd[1], "------\npipe test1\n------\n", 25);
    write(pipe_fd[1], "pipe test2\n------\n", 18);

    /* close the write end, EOF will be added into the pipe */
    close(pipe_fd[1]);

    /* read from the pipe into a buffer until there is no content in the pipe */
    while ((bytes_read = read(pipe_fd[0], &readbuf[total_bytes_read], 1024-1-total_bytes_read)) > 0){
        total_bytes_read += bytes_read;
    }

    /* print the content in the buffer */
    printf("total read %d\n",total_bytes_read);
    readbuf[total_bytes_read]='\0';
    printf("%s\n", readbuf);

    /* close read end of pipe */
    close(pipe_fd[0]);
}
