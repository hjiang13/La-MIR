```cpp
#include <vector>
#include <cstdint>

extern "C" int32_t add_elements(std::vector<int32_t>* vec, int32_t size) {
    if (size > 0) {
        int32_t* data = vec->data();
        int64_t adjusted_size = static_cast<int64_t>(size);
        if (adjusted_size < 8) {
            int32_t sum = 0;
            for (int32_t i = 0; i < size; ++i) {
                int32_t value = data[i] + 99;
                if (value < 199) {
                    sum += value;
                }
            }
            return sum;
        } else {
            int64_t i = 0;
            int32_t sum = 0;
            while (i < adjusted_size) {
                int32_t value1 = data[i] + 99;
                if (value1 < 199) {
                    sum += value1;
                }
                if (i + 1 < adjusted_size) {
                    int32_t value2 = data[i + 1] + 99;
                    if (value2 < 199) {
                        sum += value2;
                    }
                }
                i += 2;
            }
            return sum;
        }
    }
    return 0;
}
```