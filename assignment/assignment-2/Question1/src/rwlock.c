#include "rwlock.h"
#include <stdio.h>
#include <string.h>

/*
    This is the ONLY file you need to implement.
*/

void rwlock_init(rwlock_t *rwlock) {
    // TODO
}

void rwlock_acquire_read(rwlock_t *rwlock, const char *priority) {
    // TODO
    // priority is either "high priority" or "low priority"
}

void rwlock_release_read(rwlock_t *rwlock) {
    // TODO
}

void rwlock_acquire_write(rwlock_t *rwlock, const char *priority) {
    // TODO
    // priority is either "high priority" or "low priority"
}

void rwlock_release_write(rwlock_t *rwlock) {
    // TODO
}
