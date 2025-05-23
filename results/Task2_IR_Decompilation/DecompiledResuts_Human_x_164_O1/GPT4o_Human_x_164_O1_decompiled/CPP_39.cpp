```cpp
#include <iostream>

int prime_fibi(int n) {
    int result = 0;
    for (int i = 1, j = 2; i < n; ++i) {
        int is_prime = 1;
        for (int k = 2; k * k <= j; ++k) {
            if (j % k == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            result = j;
        }
        j++;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << prime_fibi(n) << std::endl;
    return 0;
}
```