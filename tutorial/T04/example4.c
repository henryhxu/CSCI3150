#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int shared_data = 0;
pthread_rwlock_t rwlock;

void* reader(void* arg) {
    long tid = (long)arg; // Get the thread ID
    pthread_rwlock_rdlock(&rwlock);
    printf("Reader %ld begins reading...\n", tid);
    sleep(1);
    printf("Reader %ld: %d\n", tid, shared_data);
    sleep(1);
    printf("Reader %ld ends reading.\n", tid);
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

void* writer(void* arg) {
    long tid = (long)arg; // Get the thread ID
    pthread_rwlock_wrlock(&rwlock);
    printf("Writer %ld begins writing...\n", tid);
    sleep(1);
    shared_data++;
    printf("Writer %ld: %d\n", tid, shared_data);
    sleep(1);
    printf("Writer %ld ends writing.\n", tid);
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, r3, w2;
    pthread_rwlock_init(&rwlock, NULL);
    
    // Pass thread IDs as arguments
    pthread_create(&r1, NULL, reader, (void*)1);
    pthread_create(&r2, NULL, reader, (void*)2);
    pthread_create(&w1, NULL, writer, (void*)1);
    pthread_create(&r3, NULL, reader, (void*)3);
    pthread_create(&w2, NULL, writer, (void*)2);
    
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    pthread_join(r3, NULL);
    pthread_join(w2, NULL);
    
    pthread_rwlock_destroy(&rwlock);
    return 0;
}