#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the semaphore created in Process A
    sem_t *sem = sem_open("/mysem", 0);
    sem_wait(sem);
    printf("Process B enters the critical section.\n");
    sleep(5); 
    printf("Process B leaves the critical section.\n");
    sem_post(sem);
    sem_close(sem);
    return 0;
}
