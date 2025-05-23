```cpp
#include <vector>
#include <string>
#include <stdexcept>

std::vector<std::string> all_prefixes(const std::string& input) {
    std::vector<std::string> result;
    std::string prefix;
    for (size_t i = 0; i < input.length(); ++i) {
        prefix += input[i];
        result.push_back(prefix);
    }
    return result;
}

int main() {
    std::string input = "example";
    std::vector<std::string> prefixes = all_prefixes(input);
    for (const auto& prefix : prefixes) {
        // Do something with each prefix
    }
    return 0;
}
```