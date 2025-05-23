```cpp
#include <string>
#include <algorithm>

void anti_shuffle(std::string &result, const std::string &input) {
    result.clear();
    result.resize(input.size());
    std::string temp;

    for (std::size_t i = 0; i < input.size(); ++i) {
        temp.push_back(input[i]);
        if (temp.back() == 32) {
            std::sort(temp.begin(), temp.end());
            std::copy(temp.begin(), temp.end(), result.begin() + i - temp.size() + 1);
            temp.clear();
        }
    }
    if (!temp.empty()) {
        std::sort(temp.begin(), temp.end());
        std::copy(temp.begin(), temp.end(), result.begin() + input.size() - temp.size());
    }
}
```