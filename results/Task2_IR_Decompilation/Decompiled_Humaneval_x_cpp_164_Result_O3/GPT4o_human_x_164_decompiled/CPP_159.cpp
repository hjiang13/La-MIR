```cpp
#include <vector>
#include <cstddef>
#include <cstring>

extern "C" void* operator new(std::size_t size) {
    return malloc(size);
}

extern "C" void operator delete(void* ptr) noexcept {
    free(ptr);
}

void example_function(std::vector<int>& vec, int a, int b, int c) {
    if (c < b) {
        vec.resize(a + c);
        vec[0] = a + c;
    } else {
        int temp = c - b;
        vec.resize(a + b);
        vec[0] = a + b;
    }
    vec[1] = nullptr; // Placeholder for pointer (to maintain structure)
}
```