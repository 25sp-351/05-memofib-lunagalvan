#include <stdio.h>
#include "fibonacci.h"
#include "memoization.h"

void run_tests() {
    printf("Testing Fibonacci function...\n");

    // test cases for Fibonacci numbers
    int test_cases[] = {0, 1, 2, 3, 10, 20, 30, 40, 50, 60, 70, 80, 90, 91};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        long long result = memoized_function(n, fibonacci);
        printf("Fibonacci(%d) = %lld\n", n, result);
    }

    printf("Fibonacci(-1) = %lld (Expected: -1)\n", memoized_function(-1, fibonacci));
    printf("Fibonacci(92) = %lld (Expected: -1)\n", memoized_function(92, fibonacci));
}

int main() {
    run_tests();
    clear_cache();
    return 0;
}