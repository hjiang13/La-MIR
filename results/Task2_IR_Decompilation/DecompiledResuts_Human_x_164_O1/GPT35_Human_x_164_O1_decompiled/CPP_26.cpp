```cpp
#include <vector>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    
    std::vector<int> temp;
    temp.clear();
    
    for (const auto& item : input) {
        if (std::find(result.begin(), result.end(), item) == result.end()) {
            result.push_back(item);
        }
    }
}
```