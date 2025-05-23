```c
#include <vector>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    int max_val = 0;
    
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] > max_val) {
            max_val = input[i];
        }
        result.push_back(max_val);
    }
}
```