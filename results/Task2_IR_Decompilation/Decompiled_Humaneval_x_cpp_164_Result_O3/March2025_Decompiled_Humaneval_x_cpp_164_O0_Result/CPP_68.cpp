```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

void pluck(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] % 2 == 0) {
            if (result.empty() || input[i] < result[0]) {
                result = {input[i], static_cast<int>(i)};
            }
        }
    }
}
```