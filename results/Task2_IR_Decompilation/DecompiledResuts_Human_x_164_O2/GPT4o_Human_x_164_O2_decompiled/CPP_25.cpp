```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void* allocate_memory(size_t size) {
    return operator new(size);
}

void deallocate_memory(void* ptr) {
    operator delete(ptr);
}

void factorize(std::vector<int>& v, int n) {
    int* old_data = nullptr;
    int* new_data = nullptr;
    size_t old_size = v.size();
    size_t new_size = 0;

    if (n < 4) {
        v.resize(0);
        return;
    }

    while (true) {
        int factor = n / 2;
        if (n % 2 == 0) {
            v.push_back(2);
            n /= 2;
        } else {
            if (n == 1) break;
            for (int i = 3; i * i <= n; i += 2) {
                while (n % i == 0) {
                    v.push_back(i);
                    n /= i;
                }
            }
            if (n > 1) {
                v.push_back(n);
            }
            break;
        }
    }
}
```