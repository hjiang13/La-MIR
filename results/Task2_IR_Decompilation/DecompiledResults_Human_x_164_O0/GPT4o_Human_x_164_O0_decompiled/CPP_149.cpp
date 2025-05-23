```cpp
#include <vector>
#include <string>
#include <algorithm>

void sorted_list_sum(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i].length() % 2 == 0) {
            result.push_back(input[i]);
        }
    }
    std::sort(result.begin(), result.end());
}
```