#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_MEAT 5
#define MAX_BREAD 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_meat = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_bread = PTHREAD_COND_INITIALIZER;

int meat = 0;
int bread = 0;
int shawarma = 0;

void* meat_supplier(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (meat == 0) {
            meat = MAX_MEAT;  
            printf("Meat supplier refilled the meat.\n");
            pthread_cond_signal(&cond_meat); // Notify producers
        }
        pthread_mutex_unlock(&mutex);
        //sleep(2); // Simulate time taken to supply meat
    }
    return NULL;
}

void* bread_supplier(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (bread < MAX_BREAD) {
            bread++;
            printf("Bread supplier added a bread. Total bread: %d\n", bread);
            pthread_cond_signal(&cond_bread); // Notify producers
        }
        pthread_mutex_unlock(&mutex);
        //sleep(1); // Simulate time taken to supply bread
    }
    return NULL;
}

void* producer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        // when ingredient not enough, wait
        while (meat < 1 || bread < 2) {
            while (meat < 1) {
                pthread_cond_wait(&cond_meat, &mutex); // Wait for meat
            }
            while (bread < 2) {
                pthread_cond_wait(&cond_bread, &mutex); // Wait for bread
            }
        }
        // Produce one shawarma
        meat--;
        bread -= 2;
        printf("Producer made a shawarma. Remaining meat: %d, bread: %d\n", meat, bread);
        shawarma++;
        pthread_mutex_unlock(&mutex);
        //sleep(2); // Simulate time taken to make shawarma
    }
    return NULL;
}

int main() {
    pthread_t meat_supplier_thread, bread_supplier_thread, producer_threads[2];
    // Create threads
    pthread_create(&meat_supplier_thread, NULL, meat_supplier, NULL);
    pthread_create(&bread_supplier_thread, NULL, bread_supplier, NULL);
    for (int i = 0; i < 2; i++) {
        pthread_create(&producer_threads[i], NULL, producer, NULL);
    }
    // Join threads (not really needed in this infinite loop scenario)
    pthread_join(meat_supplier_thread, NULL);
    pthread_join(bread_supplier_thread, NULL);
    for (int i = 0; i < 2; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    return 0;
}