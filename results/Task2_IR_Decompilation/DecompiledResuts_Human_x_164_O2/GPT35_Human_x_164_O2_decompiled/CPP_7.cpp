```cpp
#include <iostream>
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
    std::vector<std::string> input = {"apple", "banana", "cherry", "date"};
    std::vector<std::string> result;
    
    filter_by_substring(result, input, "a");
    
    for (const auto& str : result) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
```