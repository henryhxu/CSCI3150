#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a semaphore
    sem_t *sem = sem_open("/mysem", O_CREAT, 0644, 1);
    sem_wait(sem);
    printf("Process A enters the critical section.\n");
    sleep(5);
    printf("Process A leaves the critical section.\n");
    sem_post(sem);
    sem_close(sem);
    sem_unlink("/mysem");
    return 0;
}
