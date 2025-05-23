```cpp
#include <vector>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (value < 1) {
        return;
    }

    size_t size = vec.size();
    if (size == 0) {
        vec.push_back(value);
        return;
    }

    int newSize = size + 1;
    if (newSize > vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int* newData = new int[newSize];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = vec[i];
    }
    newData[size - 1] = value;

    delete[] vec.data();
    vec.data() = newData;
}
```