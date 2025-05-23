```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void filter_by_prefix(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& prefix) {
    result.clear();
    size_t prefix_length = prefix.length();
    
    for (const auto& str : input) {
        if (str.substr(0, prefix_length) == prefix) {
            result.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apricot", "blueberry"};
    std::vector<std::string> result;
    std::string prefix = "ap";

    filter_by_prefix(result, input, prefix);

    for (const auto& str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
```