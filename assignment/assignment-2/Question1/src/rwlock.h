#ifndef RWLOCK_H
#define RWLOCK_H

#include <pthread.h>

/*
    DONT modify this file.
*/

// the definition of rwlock_t
typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t readers_cond;
    pthread_cond_t writers_cond;
    int active_readers;
    int active_writers;
    int waiting_high_priority_readers;
    int waiting_high_priority_writers;
    int waiting_low_priority_readers;
    int waiting_low_priority_writers;
} rwlock_t;

// lock functions
void rwlock_init(rwlock_t *rwlock);
void rwlock_acquire_read(rwlock_t *rwlock, const char *priority);
void rwlock_release_read(rwlock_t *rwlock);
void rwlock_acquire_write(rwlock_t *rwlock, const char *priority);
void rwlock_release_write(rwlock_t *rwlock);

#endif // RWLOCK_H