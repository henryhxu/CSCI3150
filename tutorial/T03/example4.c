/* example for using dup2() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char *file_path = "./test0.txt";
    int fd = open(file_path, O_RDWR);

    /* redirect standard output to the file */
    dup2(fd,STDOUT_FILENO);

    printf("------dup test ends------\n");
    close(fd);

    return 0;
}
