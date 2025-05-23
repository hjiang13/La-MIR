```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

void sort_even(std::vector<float>& vec) {
    if (vec.empty()) return;

    float* begin = vec.data();
    float* end = begin + vec.size();
    
    if (end - begin <= 64) {
        std::sort(begin, end);
    } else {
        // Introsort
        std::sort(begin, end);
    }
}

void realloc_insert(std::vector<float>& vec, float* position, float value) {
    if (position < vec.data() || position > vec.data() + vec.size()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t index = position - vec.data();
    vec.push_back(0); // Increase size

    std::memmove(vec.data() + index + 1, vec.data() + index, (vec.size() - index - 1) * sizeof(float));
    vec[index] = value;
}

void insertion_sort(float* begin, float* end) {
    for (float* i = begin + 1; i < end; ++i) {
        float value = *i;
        float* j = i - 1;
        while (j >= begin && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

void final_insertion_sort(float* begin, float* end) {
    insertion_sort(begin, end);
}
```