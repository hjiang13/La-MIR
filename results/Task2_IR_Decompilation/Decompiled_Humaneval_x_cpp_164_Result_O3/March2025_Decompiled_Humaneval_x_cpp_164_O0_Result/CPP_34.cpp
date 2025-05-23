```cpp
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

std::vector<int> unique(std::vector<int> input) {
    std::vector<int> result;
    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(result.begin(), result.end(), input[i]) == result.end()) {
            result.push_back(input[i]);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}
```