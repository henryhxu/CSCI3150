#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rwlock.h"

/*
    DONT modify the given parts. You may add your own test cases at the end of main function,
    but DONT change other parts otherwise the test program will fail to analyze the generated log correctly.
*/

#define NUM_READERS 20
#define NUM_WRITERS 10

rwlock_t lock;
int counter = 0; 

typedef struct {
    int id;
    char priority[20];
} thread_arg;

void* reader(void* arg) {
    thread_arg *targ = (thread_arg*) arg;
    rwlock_acquire_read(&lock, targ->priority);
    printf("[Reader - %s Priority] Reader %d begins reading\n", targ->priority, targ->id);
    usleep(100000);
    printf("[Reader - %s Priority] Reader %d reads counter as %d\n", targ->priority, targ->id, counter);
    usleep(100000);
    printf("[Reader - %s Priority] Reader %d finished reading\n", targ->priority, targ->id);
    rwlock_release_read(&lock);
    return NULL;
}

void* writer(void* arg) {
    thread_arg *targ = (thread_arg*) arg;
    rwlock_acquire_write(&lock, targ->priority);
    printf("[Writer - %s Priority] Writer %d is writing\n", targ->priority, targ->id);
    usleep(200000);
    counter++;
    printf("[Writer - %s Priority] Writer %d increments counter to %d\n", targ->priority, targ->id, counter);
    usleep(200000);
    printf("[Writer - %s Priority] Writer %d finished writing\n", targ->priority, targ->id);
    rwlock_release_write(&lock);
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    thread_arg reader_args[NUM_READERS];
    thread_arg writer_args[NUM_WRITERS];
    
    system("mkdir -p logs");

    rwlock_init(&lock);

    // Testcase 1.
    freopen("logs/reader_preference.log", "w", stdout);
    printf("=== Test Case 1: Readers High Priority, Writers Low Priority ===\n");

    for (int i = 0; i < NUM_READERS; i++) {
        reader_args[i].id = i + 1;
        strcpy(reader_args[i].priority, "high priority");
        if (pthread_create(&readers[i], NULL, reader, &reader_args[i]) != 0) {
            perror("Failed to create reader thread");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_args[i].id = i + 1;
        strcpy(writer_args[i].priority, "low priority");
        if (pthread_create(&writers[i], NULL, writer, &writer_args[i]) != 0) {
            perror("Failed to create writer thread");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    fflush(stdout);
    freopen("/dev/tty", "a", stdout); // Redirect stdout back to terminal
    printf("Test Case 1 done. Log is saved in logs/reader_preference.log.\n");

    // You may add your own test cases here to test different priority combinations.
    // Examples to consider:
    // - Writers with high priority, Readers with low priority
    // - Both with high priority
    // - Both with low priority
    // - Mixed priorities
    
    printf("Done. Go to logs/ for human checking. Or run make test to see if you can pass.\n");

    return 0;
}