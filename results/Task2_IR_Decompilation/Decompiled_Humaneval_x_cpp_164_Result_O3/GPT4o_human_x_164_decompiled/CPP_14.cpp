```cpp
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& result, const std::string& str) {
    result.clear();
    std::string prefix;
    
    for (size_t i = 0; i < str.size(); ++i) {
        prefix += str[i];
        result.push_back(prefix);
    }
}
```