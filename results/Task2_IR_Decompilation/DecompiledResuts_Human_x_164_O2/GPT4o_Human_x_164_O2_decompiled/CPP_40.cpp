```cpp
#include <vector>
#include <cstdint>

extern "C" bool triples_sum_to_zero(std::vector<int> *vec) {
    int32_t *data = vec->data();
    int32_t *end = data + vec->size();
    int64_t size = end - data;
    if (size == 0) return false;

    int64_t count = 0;
    int32_t sum = 0;
    for (int64_t i = 0; i < size; ++i) {
        sum += data[i];
        count++;
        if (sum == -count) {
            return true;
        }
    }
    return false;
}
```