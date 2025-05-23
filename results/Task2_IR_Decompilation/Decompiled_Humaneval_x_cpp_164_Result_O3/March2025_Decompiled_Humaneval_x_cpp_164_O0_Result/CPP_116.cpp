```cpp
#include <vector>
#include <cmath>
#include <stdexcept>

void sort_array(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp;
    for (size_t i = 0; i < input.size(); ++i) {
        int value = std::abs(input[i]);
        int sum = 0;
        while (value > 0) {
            sum += value % 2;
            value /= 2;
        }
        temp.push_back(sum);
    }

    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 1; j < input.size(); ++j) {
            if (temp[j] < temp[j - 1] || (temp[j] == temp[j - 1] && input[j] < input[j - 1])) {
                std::swap(temp[j], temp[j - 1]);
                std::swap(result[j], result[j - 1]);
            }
        }
    }
    result = std::move(temp);
}
```