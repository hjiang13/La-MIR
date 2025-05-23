```cpp
#include <vector>
#include <algorithm>

void rolling_max(std::vector<int>& output, const std::vector<int>& input) {
    output.clear();
    
    if (input.empty()) {
        return;
    }
    
    output.push_back(input[0]);
    
    for (size_t i = 1; i < input.size(); ++i) {
        int current = input[i];
        int max_so_far = std::max(output.back(), current);
        output.push_back(max_so_far);
    }
}
```