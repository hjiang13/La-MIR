```cpp
#include <iostream>

int fizz_buzz(int n) {
    int count = 0;
    int current = 0;

    while (current < n) {
        if (current % 11 == 0 || current % 13 == 0) {
            if (current > 0 && current % 10 == 7) {
                count++;
            }
            current /= 10;
        }
        current++;
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