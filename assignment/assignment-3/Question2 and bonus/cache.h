// cache.h

#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CACHE_SIZE 5


typedef struct {
    //To do: Define the structure of CacheLine
    /*
    Tip: You need to store the corresponding memory addresses
    and variables for the LFU, LRU, and CLOCK algorithms.
    */
} CacheLine;


typedef struct {
    CacheLine lines[CACHE_SIZE];
} CacheLinePool;

typedef struct {
    CacheLinePool *line_pool;
    unsigned int time;            // Global time counter
    int clock_pointer;            // Pointer of the Clock algorithm
} Cache;

Cache *create_cache();
void cache_access_lru(Cache *cache, unsigned int address);
void cache_access_lfu(Cache *cache, unsigned int address);
void cache_access_clock(Cache *cache, unsigned int address);
void free_cache(Cache *cache);

#endif // CACHE_H