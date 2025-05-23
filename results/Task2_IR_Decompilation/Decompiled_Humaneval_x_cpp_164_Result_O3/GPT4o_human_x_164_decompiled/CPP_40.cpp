```cpp
#include <vector>
#include <cstdint>

bool triples_sum_to_zero(std::vector<int> &vec) {
    int32_t *data = vec.data();
    int32_t *end = data + vec.size();
    int64_t count = 0;

    while (data < end) {
        int32_t value = *data++;
        count++;
        if (value == 0) {
            return false;
        }
    }

    return count == 0;
}
```