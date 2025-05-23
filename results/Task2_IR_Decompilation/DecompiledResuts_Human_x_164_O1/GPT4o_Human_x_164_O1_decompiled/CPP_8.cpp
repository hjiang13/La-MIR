```cpp
#include <vector>
#include <cstdlib>
#include <cstring>

extern "C" {
    void* operator new(std::size_t size) {
        return malloc(size);
    }

    void operator delete(void* ptr) noexcept {
        free(ptr);
    }
}

void sum_product(std::vector<int>& result, const std::vector<int>& input) {
    if (input.empty()) {
        result.resize(2);
        result[0] = 0;
        result[1] = 0;
        return;
    }

    std::size_t size = input.size();
    result.resize(2);
    int sum = 0;
    int product = 1;

    for (std::size_t i = 0; i < size; ++i) {
        sum += input[i];
        product *= input[i];
    }

    result[0] = sum;
    result[1] = product;
}
```