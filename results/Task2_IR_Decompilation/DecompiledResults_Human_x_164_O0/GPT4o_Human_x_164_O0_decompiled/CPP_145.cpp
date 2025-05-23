```cpp
#include <vector>
#include <string>
#include <cstdlib>

void order_by_points(std::vector<int> &result, const std::vector<int> &points) {
    result.clear();
    for (size_t i = 0; i < points.size(); ++i) {
        int value = abs(points[i]);
        std::string str_value = std::to_string(value);
        for (size_t j = 0; j < str_value.length(); ++j) {
            result.push_back(str_value[j] - '0');
        }
    }
}
```