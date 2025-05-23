```cpp
#include <vector>
#include <cstring>

extern "C" void* operator new(std::size_t size) {
    return malloc(size);
}

extern "C" void operator delete(void* ptr) noexcept {
    free(ptr);
}

extern "C" void eati(int a, int b, int c, int d, std::vector<int>& vec) {
    if (d < c) {
        int sum = d + a;
        vec.resize(2);
        vec[0] = sum;
        vec[1] = 0;
    } else {
        int diff = d - c;
        int sum = c + a;
        vec.resize(2);
        vec[0] = sum;
        vec[1] = diff;
    }
}
```