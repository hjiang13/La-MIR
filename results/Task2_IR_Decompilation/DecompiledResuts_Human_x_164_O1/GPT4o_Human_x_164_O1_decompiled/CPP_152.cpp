```cpp
#include <vector>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

void compare(std::vector<int>& vec1, const std::vector<int>& vec2, const std::vector<int>& vec3) {
    int* data1 = vec1.data();
    int* data2 = const_cast<int*>(vec2.data());
    int* data3 = const_cast<int*>(vec3.data());

    if (data1 == data2) {
        return;
    }

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    size_t size3 = vec3.size();

    for (size_t i = 0; i < size1; ++i) {
        int diff = data1[i] - data2[i];
        int absDiff = abs(diff);
        if (data3) {
            data3[i] = absDiff;
        }
    }

    if (data1 != data3) {
        std::memmove(data1 + 1, data1, size1 * sizeof(int));
        data1[0] = data3[0];
    }
}

void realloc_insert(std::vector<int>& vec, int* item, int* size) {
    if (vec.size() >= vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    int* new_data = static_cast<int*>(std::malloc(vec.capacity() * sizeof(int)));
    std::memcpy(new_data, vec.data(), vec.size() * sizeof(int));
    new_data[vec.size()] = *item;
    vec = std::vector<int>(new_data, new_data + vec.size() + 1);
    free(new_data);
}
```