```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

void filter_by_substring(std::vector<std::string>& output, const std::vector<std::string>& input, const std::string& substring) {
    for (const auto& str : input) {
        if (str.find(substring) != std::string::npos) {
            output.push_back(str);
        }
    }
}

int main() {
    // Example usage
    std::vector<std::string> input = {"apple", "banana", "grape", "apricot"};
    std::vector<std::string> output;
    std::string substring = "ap";

    filter_by_substring(output, input, substring);

    for (const auto& str : output) {
        std::cout << str << std::endl;
    }

    return 0;
}
```