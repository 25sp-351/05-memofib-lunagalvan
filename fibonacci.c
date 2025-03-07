#include "fibonacci.h"
#include "memoization.h"

long long fibonacci(int n) {
    if (n < 0 || n > 91) {
        return -1;
    }

    if (is_cached(n)) {
        return get_cached_value(n);
    }

    if (n == 0) {
        cache_value(0, 0);
        return 0;
    }
    if (n == 1) {
        cache_value(1, 1);
        return 1;
    }

    long long result = fibonacci(n - 1) + fibonacci(n - 2);
    cache_value(n, result);
    return result;
}