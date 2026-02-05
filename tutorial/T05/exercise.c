#include <pthread.h>
#include <stdio.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_vars[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

enum { THINKING, HUNGRY, EATING };

// Function prototypes
void test(int i);
void pickup_forks(int i);
void return_forks(int i);

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

void test(int i) {
    // TODO: Implement test function
    // Hint: Check if the philosopher can start eating
    // by ensuring neighbors are not eating.
}

void pickup_forks(int i) {
    pthread_mutex_lock(&mutex);
    // TODO: Implement pickup_forks function
    // Hint: Set state to HUNGRY and then test.
    // Wait if not able to eat.
    pthread_mutex_unlock(&mutex);
}

void return_forks(int i) {
    pthread_mutex_lock(&mutex);
    // TODO: Implement return_forks function
    // Hint: Set state to THINKING and test neighbors.
    pthread_mutex_unlock(&mutex);
}