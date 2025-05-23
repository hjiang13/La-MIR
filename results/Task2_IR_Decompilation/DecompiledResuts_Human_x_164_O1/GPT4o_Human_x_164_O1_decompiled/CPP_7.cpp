```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

void filter_by_substring(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& substring) {
    result.clear();
    for (const auto& str : input) {
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> input = {"example", "test", "sample", "substring"};
    std::vector<std::string> result;
    filter_by_substring(result, input, "sub");
    
    for (const auto& str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
```