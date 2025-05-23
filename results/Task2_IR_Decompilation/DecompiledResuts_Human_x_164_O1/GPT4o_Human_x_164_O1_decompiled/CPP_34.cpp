```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <cstring>

void unique(std::vector<int>& vec) {
    auto end = vec.end();
    auto new_end = std::unique(vec.begin(), vec.end());
    vec.erase(new_end, end);
}

void realloc_insert(std::vector<int>& vec, int* pos, int* value) {
    if (vec.size() >= vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int* new_pos = vec.data() + (pos - vec.data());
    std::memmove(new_pos + 1, new_pos, (vec.end() - new_pos) * sizeof(int));
    *new_pos = *value;
    vec.push_back(0);
}

void introsort(int* begin, int* end, long size) {
    if (size <= 64) {
        std::sort(begin, end);
    } else {
        // Custom introsort implementation
        // (omitted for brevity)
    }
}

void final_insertion_sort(int* begin, int* end) {
    // Custom insertion sort implementation
    // (omitted for brevity)
}

int main() {
    std::vector<int> vec = {1, 1, 2, 3, 3, 4, 5, 5};
    try {
        unique(vec);
        for (auto val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        int value = 6;
        realloc_insert(vec, &vec[4], &value);
        for (auto val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        introsort(vec.data(), vec.data() + vec.size(), vec.size());
        final_insertion_sort(vec.data(), vec.data() + vec.size());
        for (auto val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```