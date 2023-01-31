#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char *file_name = "my_env";
    char *argv[32] = {"my_env", NULL}; 
    char *envp[2] = { "ABC=1", NULL};

    /* execute the command */

    // execl("/bin/my_env", argv[0], NULL);
    // execlp(file_name, argv[0], NULL);
    // execle("/bin/my_env", argv[0], NULL, envp);

    // execv("/bin/my_env", argv);
    // execvp(file_name, argv);
    execvpe(file_name, argv, envp);

    printf("We just arrive at a line of code after exec()\n");

    return 0;
}