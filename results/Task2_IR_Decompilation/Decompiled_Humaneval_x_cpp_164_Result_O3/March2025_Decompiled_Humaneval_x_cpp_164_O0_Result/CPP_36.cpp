```cpp
#include <iostream>

int fizz_buzz(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 11 == 0 || i % 13 == 0) {
            int temp = i;
            while (temp > 0) {
                if (temp % 10 == 7) {
                    ++count;
                }
                temp /= 10;
            }
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