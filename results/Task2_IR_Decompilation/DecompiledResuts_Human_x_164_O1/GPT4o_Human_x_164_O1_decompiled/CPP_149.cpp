```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void sorted_list_sum(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    if (input.empty()) return;

    for (const auto& str : input) {
        if (std::find(result.begin(), result.end(), str) == result.end()) {
            result.push_back(str);
        }
    }

    std::sort(result.begin(), result.end());
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apple", "cherry"};
    std::vector<std::string> result;

    sorted_list_sum(result, input);

    for (const auto& str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
```