#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0; 
pthread_mutex_t lock;

void* increment(void* arg) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 1000000; i++) {
        counter++;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    printf("Final counter value: %d\n", counter);
    return 0;
}

