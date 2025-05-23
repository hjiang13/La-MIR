```cpp
#include <vector>
#include <cstddef>
#include <cstring>
#include <new>

void pluck(std::vector<int> &result, const std::vector<int> &input) {
    using namespace std;
    size_t input_size = input.size();
    size_t result_size = 0;

    result.clear();
    result.reserve(input_size);

    for (size_t i = 0; i < input_size; ++i) {
        if ((input[i] & 1) == 0) {
            result.push_back(input[i]);
            result_size++;
        }
    }

    result.resize(result_size);
}

extern "C" {
    void *operator new(size_t size) noexcept {
        return ::operator new(size);
    }

    void operator delete(void *ptr) noexcept {
        ::operator delete(ptr);
    }
}
```