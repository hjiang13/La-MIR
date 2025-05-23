```cpp
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& result, const std::string& input) {
    result.clear();
    std::string temp;
    
    for (size_t i = 0; i < input.size(); ++i) {
        temp = "";
        for (size_t j = i; j < input.size(); ++j) {
            temp += input[j];
            result.push_back(temp);
        }
    }
}
```