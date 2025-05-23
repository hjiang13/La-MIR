```cpp
#include <vector>
#include <string>

void filter_by_substring(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& substring) {
    result.clear();
    
    for (const auto& str : input) {
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> input = {"string1", "string2", "substring", "another"};
    std::vector<std::string> result;
    std::string substring = "sub";
    
    filter_by_substring(result, input, substring);
    
    for (const auto& str : result) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
```