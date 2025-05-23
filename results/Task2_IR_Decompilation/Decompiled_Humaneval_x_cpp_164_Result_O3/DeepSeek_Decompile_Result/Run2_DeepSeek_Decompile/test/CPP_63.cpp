#include <iostream>

int fib(int n) {
    int fib_array[100];
    fib_array[0] = 0;
    fib_array[1] = 0;
    fib_array[2] = 1;
    
    if (n < 3) {
        return n;
    }

    for (int i = 3; i <= n; ++i) {
        fib_array[i] = fib_array[i-1] + fib_array[i-2];
    }

    return fib_array[n];
}

int main() {
    int result = fib(10); // Example usage: Calculate the 10th Fibonacci number
    std::cout << "Fibonacci number: " << result << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fibfib(2) == 1);
    assert (fibfib(1) == 0);
    assert (fibfib(5) == 4);
    assert (fibfib(8) == 24);
    assert (fibfib(10) == 81);
    assert (fibfib(12) == 274);
    assert (fibfib(14) == 927);
}
