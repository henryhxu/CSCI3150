// main.c

#include "cache.h"

#define MAX_ADDRESS_COUNT 10000

int main() {
    Cache *cache;
    unsigned int addresses[MAX_ADDRESS_COUNT];
    int num_accesses = 0;

    FILE *file = fopen("addresses1.txt", "r");
    if (!file) {
        printf("Can not access addresses.txt\n");
        return 1;
    }

    while (fscanf(file, "%x", &addresses[num_accesses]) != EOF) {
        num_accesses++;
        if (num_accesses >= MAX_ADDRESS_COUNT) {
            printf("Too many addresses, please increase MAX_ADDRESS_COUNT\n");
            break;
        }
    }

    fclose(file);


    printf("Using LRU replacement strategy：\n");
    cache = create_cache();
    for (int i = 0; i < num_accesses; i++) {
        cache_access_lru(cache, addresses[i]);
    }
    free_cache(cache);

    printf("\nUse LFU replacement strategy:\n");
    cache = create_cache();
    for (int i = 0; i < num_accesses; i++) {
        cache_access_lfu(cache, addresses[i]);
    }
    free_cache(cache);

    printf("\nUse Clock replacement strategy:\n");
    cache = create_cache();
    for (int i = 0; i < num_accesses; i++) {
        cache_access_clock(cache, addresses[i]);
    }
    free_cache(cache);

    return 0;
}