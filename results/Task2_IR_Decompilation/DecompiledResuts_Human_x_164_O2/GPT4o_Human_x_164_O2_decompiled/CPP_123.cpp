```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void get_odd_collatz(std::vector<int>& vec, int n) {
    vec.clear();
    vec.reserve(4);
    vec.push_back(1);
    vec.push_back(nullptr);
    
    if (n == 1) {
        return;
    }

    int* current = nullptr;
    int* prev = nullptr;
    int* next = nullptr;

    while (true) {
        if (n == 1) {
            break;
        }

        int remainder = n % 2;
        int half = n / 2;

        if (remainder == 1) {
            current = vec.data() + vec.size();
            vec.push_back(n);
            n = 3 * n + 1;
        } else {
            if (vec.size() < 2) {
                throw std::length_error("vector::_M_realloc_insert");
            }
            prev = vec.data() + vec.size() - 1;
            next = current;
            *next = *prev;
            current = next + 1;
            vec.push_back(n);
            n = half;
        }

        if (n == 0) {
            break;
        }
    }

    vec.push_back(0);
}
```