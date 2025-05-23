```cpp
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> &vec) {
    float* data_begin = vec._M_impl._M_start._M_ptr;
    float* data_end = vec._M_impl._M_finish._M_ptr;
    int count = 0;

    if (data_begin == data_end) {
        return count;
    }

    int max_count = std::max((data_end - data_begin) >> 2, 1);

    for (int i = 0; i < max_count; i++) {
        float val = std::ceil(*data_begin);
        float square = val * val;
        float index_float = static_cast<float>(count);
        float result = square + index_float;
        count = static_cast<int>(result);
        data_begin++;
    }

    return count;
}
```