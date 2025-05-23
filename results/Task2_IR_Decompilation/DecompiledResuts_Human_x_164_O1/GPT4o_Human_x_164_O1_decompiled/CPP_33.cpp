```cpp
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void throw_bad_alloc() {
    throw std::bad_alloc();
}

void* allocate_memory(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) throw_bad_alloc();
    return ptr;
}

void sort_third(std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> temp_vec;

    if (vec1.size() == 0 || vec2.size() == 0) {
        return;
    }

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    size_t new_size = size1 + size2;

    if (new_size > size1 + size2) {
        throw_length_error("vector::_M_realloc_insert");
    }

    temp_vec.reserve(new_size);
    
    for (size_t i = 0; i < size1; ++i) {
        temp_vec.push_back(vec1[i]);
    }

    for (size_t i = 0; i < size2; ++i) {
        temp_vec.push_back(vec2[i]);
    }

    std::sort(temp_vec.begin(), temp_vec.end());

    vec1 = std::move(temp_vec);
}

int main() {
    std::vector<int> vec1 = {3, 1, 4};
    std::vector<int> vec2 = {2, 5};

    sort_third(vec1, vec2);

    for (const auto& val : vec1) {
        std::cout << val << " ";
    }

    return 0;
}
```