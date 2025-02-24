#include <stdlib.h>
#include "fib.h"

static long long *memo = NULL;
static int memo_size = 0;

void init_memo(void) {
    memo_size = 93;
    memo = (long long*)calloc(memo_size, sizeof(long long));
    for (int i = 0; i < memo_size; i++) {
        memo[i] = -1;
    }

    if (memo) {
        memo[0] = 0;
        memo[1] = 1;
    }
}

void cleanup_memo(void) {
    free(memo);
    memo = NULL;
}

long long fibonacci(int n) {
    if (n < 0) return -1;
    if (n >= memo_size) return -1;
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
