// cache.c

#include "cache.h"

// Initialize Cache
Cache *create_cache() {
    Cache *cache = (Cache *)malloc(sizeof(Cache));
    cache->line_pool = (CacheLinePool *)malloc(sizeof(CacheLinePool));
    cache->time = 0;
    cache->clock_pointer = 0;

    for (int i = 0; i < CACHE_SIZE; i++) {
        //To do: Initialize each line of the Cache
    }

    return cache;
}


void cache_access_lru(Cache *cache, unsigned int address) {
    //To do: Implement the LRU algorithm


}

void cache_access_lfu(Cache *cache, unsigned int address) {
    //To do: Implement the LFU algorithm

}

void cache_access_clock(Cache *cache, unsigned int address) {
    // Bonus part. You can leave it to blank if you need these bonus.
    // To do: Implement the CLOCK algorithm

}

void free_cache(Cache *cache) {
    free(cache->line_pool);
    free(cache);
}