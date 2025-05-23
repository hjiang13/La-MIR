```cpp
#include <vector>

bool has_close_elements(std::vector<float> *vec, float val) {
    float *data_end = vec->data() + vec->size();
    float *data_begin = vec->data();
    size_t size_diff = data_end - data_begin;
    size_t max_diff = std::max(size_diff, static_cast<size_t>(1));

    for (size_t i = 0; i < max_diff - 1; ++i) {
        float diff = std::abs(data_begin[i] - data_begin[i + 1]);
        if (diff < val) {
            return true;
        }
    }

    return false;
}
```