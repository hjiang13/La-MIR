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

void memmove_custom(void* dest, const void* src, size_t n) {
    std::memmove(dest, src, n);
}

void memset_custom(void* s, int c, size_t n) {
    std::memset(s, c, n);
}

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    if (input.empty()) {
        result.clear();
        return;
    }

    size_t input_size = input.size();
    size_t required_size = ((input_size - 1) * 2) + 1; 
    if (required_size < input_size) throw_length_error("vector::_M_realloc_insert");
    
    result.resize(required_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i * 2] = input[i];
        if (i < input_size - 1) {
            result[i * 2 + 1] = value;
        }
    }
}
```