#include <stdio.h>
extern char** environ;

int main(int argc, char** argv){
    printf("[ENV]\n");

    int i;
    for(i=0; environ[i]!=NULL; ++i)
    {
        printf("%s\n", environ[i]);
    }
    return 0;

}