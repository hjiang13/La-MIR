```cpp
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>

void unique(std::vector<int>& v) {
    if (v.empty()) return;

    auto end = std::unique(v.begin(), v.end());
    v.erase(end, v.end());
}

void realloc_insert(std::vector<int>& vec, int* position, int* value) {
    size_t old_size = vec.size();
    if (position < vec.data() || position > vec.data() + old_size) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    size_t index = position - vec.data();
    size_t new_size = old_size + 1;
    vec.resize(new_size);
    std::move(vec.begin() + index, vec.end() - 1, vec.begin() + index + 1);
    vec[index] = *value;
}

void introsort(int* start, int* end, size_t size) {
    // Implementation of introsort
}

void final_insertion_sort(int* start, int* end) {
    // Implementation of final insertion sort
}
```