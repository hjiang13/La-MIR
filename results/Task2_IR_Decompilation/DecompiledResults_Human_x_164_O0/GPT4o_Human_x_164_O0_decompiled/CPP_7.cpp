```cpp
#include <vector>
#include <string>
#include <stdexcept>

void filter_by_substring(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& substring) {
    for (size_t i = 0; i < input.size(); ++i) {
        const std::string& str = input[i];
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
        }
    }
}
```