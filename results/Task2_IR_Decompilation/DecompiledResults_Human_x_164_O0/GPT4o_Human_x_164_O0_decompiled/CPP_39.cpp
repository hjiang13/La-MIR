```cpp
#include <iostream>

int prime_fibi(int n) {
    int a = 1, b = 2, i = 0, prime = 0;
    while (i < n) {
        int temp = a;
        a = b;
        b = temp + b;
        for (int j = 2; j * j <= b; j++) {
            if (b % j == 0) {
                break;
            }
            if (j == (b / j)) {
                prime = b;
                break;
            }
        }
        if (b == prime) {
            ++i;
        }
    }
    return prime;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "The " << n << "th prime Fibonacci number is: " << prime_fibi(n) << std::endl;
    return 0;
}
```