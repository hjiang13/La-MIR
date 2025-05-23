```cpp
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

void sort_array(std::vector<int> &result, const std::vector<int> &source) {
    if (source.empty()) {
        result.clear();
        return;
    }

    size_t size = source.size();
    result.resize(size);
    std::memcpy(result.data(), source.data(), size * sizeof(int));

    for (size_t i = 1; i < size; ++i) {
        int key = result[i];
        size_t j = i - 1;
        while (j < size && result[j] > key) {
            result[j + 1] = result[j];
            if (j == 0) break;
            --j;
        }
        result[j + 1] = key;
    }
}
```