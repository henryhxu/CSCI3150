#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_barrier = PTHREAD_COND_INITIALIZER;
int count = 0;

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d reached the barrier.\n", id);

    pthread_mutex_lock(&mutex);
    count++;
    if (count < NUM_THREADS) {
        pthread_cond_wait(&cond_barrier, &mutex);
    } else {
        pthread_cond_broadcast(&cond_barrier);
    }
    pthread_mutex_unlock(&mutex);

    printf("Thread %d passed the barrier.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}