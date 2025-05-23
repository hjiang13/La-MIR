#include <iostream>

int fib(int n) {
    int fib_array[100]{0, 0, 2, 0};
    
    if (n < 4) {
        return fib_array[n];
    }
    
    fib_array[4] = 2;
    
    if (n == 5) {
        return 5;
    }
    
    for (int i = 6; i <= n; ++i) {
        if (i % 2 == 0) {
            fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
        } else {
            fib_array[i] = fib_array[i - 1] + 2 * fib_array[i - 2] - fib_array[i - 3];
        }
    }
    
    return fib_array[n];
}

int main() {
    std::cout << "Fibonacci number: " << fib(10) << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
