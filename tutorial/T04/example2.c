#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0; 
pthread_mutex_t lock;

void* increment(void* arg) {
    // pthread_mutex_lock(&lock);
    for (int i = 0; i < 1000000; i++) {
        counter++;
    }
    // pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    // no lock used
    // pthread_mutex_init(&lock, NULL); // initialize the mutex 'lock'.
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final value of shared resource counter: %d\n", counter);
    // pthread_mutex_destroy(&lock); // destroy the mutex 'lock'.
    return 0;
}
