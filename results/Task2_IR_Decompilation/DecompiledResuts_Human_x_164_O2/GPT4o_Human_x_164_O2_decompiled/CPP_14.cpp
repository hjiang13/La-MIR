```cpp
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& prefixes, const std::string& str) {
    prefixes.clear();
    std::string prefix;
    for (size_t i = 0; i < str.size(); ++i) {
        prefix += str[i];
        prefixes.push_back(prefix);
    }
}
```