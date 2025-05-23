#include <iostream>

int fibi(int n) {
    int fib[1000];
    fib[0] = 0;
    fib[1] = 1;

    if (n < 2) {
        return fib[n];
    }

    fib[2] = 1;

    if (n == 3) {
        return fib[2];
    }

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main() {
    int result = fibi(10); // Example usage
    std::cout << "Fibonacci number: " << result << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib(10) == 55);
    assert (fib(1) == 1);
    assert (fib(8) == 21);
    assert (fib(11) == 89);
    assert (fib(12) == 144);
}
