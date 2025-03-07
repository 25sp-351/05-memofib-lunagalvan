#ifndef MEMOIZATION_H
#define MEMOIZATION_H

#include <stdbool.h>

typedef long long (*provider_func)(int);

void initialize_cache();

bool is_cached(int n);

long long get_cached_value(int n);

void cache_value(int n, long long value);

long long memoized_function(int n, provider_func provider);

void clear_cache();

#endif