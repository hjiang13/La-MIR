```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void sorted_list_sum(std::vector<std::string> &result, const std::vector<std::string> &input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    auto it1 = input.begin();
    auto it2 = input.begin() + 1;

    while (it2 != input.end()) {
        if (*it1 == *it2) {
            ++it2;
        } else {
            result.push_back(*it1);
            it1 = it2;
            ++it2;
        }
    }

    result.push_back(*it1);
}

int main() {
    std::vector<std::string> input = {"apple", "apple", "banana", "banana", "cherry"};
    std::vector<std::string> result;
    
    sorted_list_sum(result, input);

    for (const auto &str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
```