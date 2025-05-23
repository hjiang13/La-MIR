```cpp
#include <vector>
#include <iostream>
#include <stdexcept>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void throw_bad_alloc() {
    throw std::bad_alloc();
}

void* operator new(std::size_t size) {
    void* p = std::malloc(size);
    if (!p) throw_bad_alloc();
    return p;
}

class Vector {
public:
    std::vector<int> data;

    Vector() {}

    void insert(int value) {
        if (data.size() >= data.capacity()) {
            size_t new_capacity = data.capacity() == 0 ? 1 : data.capacity() * 2;
            if (new_capacity > SIZE_MAX / sizeof(int)) throw_length_error("vector::_M_realloc_insert");
            int* new_data = static_cast<int*>(operator new(new_capacity * sizeof(int)));
            std::memcpy(new_data, data.data(), data.size() * sizeof(int));
            operator delete(data.data());
            data.data = new_data;
            data.capacity = new_capacity;
        }
        data.push_back(value);
    }
};

int main() {
    Vector vec;
    for (int i = 0; i < 10; ++i) {
        vec.insert(i);
    }

    for (const auto& val : vec.data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```