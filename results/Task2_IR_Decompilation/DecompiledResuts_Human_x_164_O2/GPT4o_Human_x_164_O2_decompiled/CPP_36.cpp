```cpp
#include <iostream>

int fizz_buzz(int n) {
    if (n <= 0) return 0;

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 11 == 0 && i % 13 != 0) {
            // Do nothing for multiples of 11 not multiples of 13
        } else if (i % 10 == 7) {
            count++;
        }
    }
    return count;
}

int main() {
    int input;
    std::cin >> input;
    std::cout << fizz_buzz(input) << std::endl;
    return 0;
}
```