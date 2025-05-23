```cpp
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

void sorted_list_sum(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    if (input.empty()) return;

    std::string first, second;
    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            first = input[i];
        } else {
            second = input[i];
            if (first == second) continue;
            result.push_back(first + second);
        }
    }
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apple", "orange"};
    std::vector<std::string> result;
    sorted_list_sum(result, input);
    
    for (const std::string& str : result) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
```