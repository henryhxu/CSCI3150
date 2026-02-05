#include <pthread.h>
#include <stdio.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_vars[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

enum { THINKING, HUNGRY, EATING };

void test(int i) {
    if (state[i] == HUNGRY && 
        state[(i + 4) % NUM_PHILOSOPHERS] != EATING && 
        state[(i + 1) % NUM_PHILOSOPHERS] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond_vars[i]);
    }
}

void pickup_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&cond_vars[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void return_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test((i + 4) % NUM_PHILOSOPHERS);
    test((i + 1) % NUM_PHILOSOPHERS);
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* arg) {
    int i = *(int*)arg;
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        pickup_forks(i);
        printf("Philosopher %d is eating.\n", i);
        return_forks(i);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_init(&cond_vars[i], NULL);
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_destroy(&cond_vars[i]);
    }

    return 0;
}