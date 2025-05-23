```cpp
#include <vector>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    result.reserve(input.size());

    int* input_data = input.data();
    int* result_data = result.data();

    int* input_end = input_data + input.size();
    int* result_end = result_data + result.size();

    int max_value = 0;

    for (int* i = input_data; i != input_end; ++i) {
        if (*i > max_value) {
            max_value = *i;
        }

        *result_data = max_value;
        ++result_data;
    }
}
```