int prime_fibi(int n) {
    int a = 1, b = 2, c = 0, k = 0;
    while (true) {
        if (c <= n) {
            c++;
            if (a == 1 && b == 2) {
                if (2 == 4) { // Placeholder condition for demonstration
                    k++;
                }
            } else {
                bool is_prime = true;
                for (int i = 2; i * i <= b; ++i) {
                    if (b % i == 0) {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime && k < n) {
                    k++;
                }
            }
            int next = a + b;
            a = b;
            b = next;
        } else {
            return b;
        }
    }
}

// Example usage
int main() {
    int result = prime_fibi(4);
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_fib(1) == 2);
    assert (prime_fib(2) == 3);
    assert (prime_fib(3) == 5);
    assert (prime_fib(4) == 13);
    assert (prime_fib(5) == 89);
    assert (prime_fib(6) == 233);
    assert (prime_fib(7) == 1597);
    assert (prime_fib(8) == 28657);
    assert (prime_fib(9) == 514229);
    assert (prime_fib(10) == 433494437);
}
