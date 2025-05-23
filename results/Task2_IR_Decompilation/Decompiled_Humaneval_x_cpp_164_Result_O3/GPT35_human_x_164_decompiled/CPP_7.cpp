```cpp
#include <vector>
#include <string>

void filter_by_substring(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& substring) {
    result.clear();
    for (const std::string& str : input) {
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "cherry"};
    std::vector<std::string> result;
    std::string substring = "an";

    filter_by_substring(result, input, substring);

    for (const std::string& str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
```