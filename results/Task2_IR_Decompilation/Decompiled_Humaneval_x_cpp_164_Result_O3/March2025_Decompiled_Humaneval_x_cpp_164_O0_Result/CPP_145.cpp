```cpp
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

void order_by_points(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp;
    for (size_t i = 0; i < input.size(); ++i) {
        int absValue = std::abs(input[i]);
        std::string str = std::to_string(absValue);
        int sum = 0;
        for (size_t j = 1; j < str.length(); ++j) {
            sum += str[j] - '0';
        }
        if (input[i] > 0) {
            sum += str[0] - '0';
        } else {
            sum -= str[0] - '0';
        }
        temp.push_back(sum);
    }

    for (size_t i = 0; i < temp.size(); ++i) {
        for (size_t j = 1; j < temp.size(); ++j) {
            if (temp[j - 1] > temp[j]) {
                std::swap(temp[j - 1], temp[j]);
                std::swap(result[j - 1], result[j]);
            }
        }
    }
    result = std::move(temp);
}
```