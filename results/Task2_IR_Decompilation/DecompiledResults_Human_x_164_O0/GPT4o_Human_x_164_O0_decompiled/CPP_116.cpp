```cpp
#include <vector>
#include <cstdlib>

void sort_array(std::vector<int> &result, const std::vector<int> &input) {
    result.clear();
    for (size_t i = 0; i < input.size(); i++) {
        int abs_value = abs(input[i]);
        if (abs_value > 0) {
            int remainder = abs_value % 2;
            result.push_back(remainder);
            abs_value /= 2;
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] > 0) {
            result.push_back(result[i]);
            result[i] = result[result.size() - 2];
            result[result.size() - 2] = result[i];
        }
    }
}
```