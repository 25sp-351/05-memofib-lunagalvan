#include "memoization.h"
#include <stdlib.h>

#define MAX_CACHE_SIZE 92

static long long cache[MAX_CACHE_SIZE];
static bool initialized = false;

void initialize_cache() {
    if (!initialized) {
        for (int i = 0; i < MAX_CACHE_SIZE; i++) {
            cache[i] = -1;
        }
        initialized = true;
    }
}

bool is_cached(int n) {
    return cache[n] != -1;
}

long long get_cached_value(int n) {
    return cache[n];
}

void cache_value(int n, long long value) {
    cache[n] = value;
}

long long memoized_function(int n, provider_func provider) {
    if (n < 0 || n >= MAX_CACHE_SIZE) {
        return -1;
    }

    initialize_cache();

    if (is_cached(n)) {
        return get_cached_value(n);
    }

    long long result = provider(n);
    cache_value(n, result);
    return result;
}

void clear_cache() {
    for (int i = 0; i < MAX_CACHE_SIZE; i++) {
        cache[i] = -1;
    }
}