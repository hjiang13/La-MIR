```cpp
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& prefixes, const std::string& str) {
    prefixes.clear();
    prefixes.push_back("");

    for (size_t i = 0; i < str.length(); ++i) {
        std::string prefix = prefixes.back() + str[i];
        prefixes.push_back(prefix);
    }
}
```