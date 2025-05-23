```cpp
#include <iostream>

int fizz_buzz(int n) {
    if (n <= 0) return 0;

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 11 == 0 && i % 13 == 0) {
            count++;
        } else if (i % 10 == 7) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fizz_buzz(n) << std::endl;
    return 0;
}
```