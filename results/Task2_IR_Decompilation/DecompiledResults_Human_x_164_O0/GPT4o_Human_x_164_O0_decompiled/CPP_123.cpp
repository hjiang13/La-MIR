```cpp
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iostream>

void get_odd_collatz(std::vector<int>& vec, int n) {
    vec = std::vector<int>{1}; // Initialize vector with 1
    if (n <= 1) return;

    while (n != 1) {
        if (n % 2 == 1) {
            vec.push_back(n);
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
    }

    std::sort(vec.begin(), vec.end());
}

int main() {
    std::vector<int> collatz_sequence;
    get_odd_collatz(collatz_sequence, 5);
    for (int num : collatz_sequence) {
        std::cout << num << " ";
    }
    return 0;
}
```