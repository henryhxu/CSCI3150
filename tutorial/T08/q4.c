#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define NUM_SEATS 5      // Number of available seats
#define NUM_WAITERS 3    // Number of available waiters
#define NUM_CUSTOMERS 10 // Number of customers

sem_t seats;    // Semaphore for available seats
sem_t waiters;  // Semaphore for available waiters

void* customer(void* type) {
    sem_wait(&seats); 
    //seats--;
    sem_wait(&waiters);   
    printf("ordering\n"); //order(); // The customer is ordering.
    sem_post(&waiters);
    printf("eating\n"); //eat(); // The customer finishes eating.
    sem_post(&seats);
    pthread_exit(NULL);
}

int main() {
    pthread_t customers[NUM_CUSTOMERS];
    sem_init(&seats, 0, NUM_SEATS);
    sem_init(&waiters, 0, NUM_WAITERS);
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_create(&customers[i], NULL, customer, NULL);
    }
    /* ... */
}
