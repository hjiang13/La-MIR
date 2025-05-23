```cpp
#include <vector>
#include <stdexcept>
#include <cmath>
#include <cstring>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    float temp[2];
    float* input_start = const_cast<float*>(input.data());
    float* input_end = input_start + input.size();
    size_t count = 0;

    while (input_start < input_end) {
        float first = *input_start++;
        float second = input_start < input_end ? *input_start++ : first;

        if (first > second) {
            temp[0] = first;
            temp[1] = second;
        } else {
            temp[0] = second;
            temp[1] = first;
        }

        if (count == result.size()) {
            throw std::length_error("cannot create std::vector larger than max_size()");
        }

        std::memcpy(result.data() + count * 2, temp, 2 * sizeof(float));
        count++;
    }
}
```