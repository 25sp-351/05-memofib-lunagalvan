#include <stdio.h>
#include <assert.h>
#include "fib.h"

void test_fibonacci(void) {

    init_memo();
    
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 2);
    assert(fibonacci(4) == 3);
    assert(fibonacci(5) == 5);
    assert(fibonacci(6) == 8);
    assert(fibonacci(10) == 55);
    
    // Test error cases
    assert(fibonacci(-1) == -1);
    assert(fibonacci(93) == -1);  

    cleanup_memo();
    
    printf("All tests passed!");
}

int main(void) {
    test_fibonacci();
    return 0;
}
