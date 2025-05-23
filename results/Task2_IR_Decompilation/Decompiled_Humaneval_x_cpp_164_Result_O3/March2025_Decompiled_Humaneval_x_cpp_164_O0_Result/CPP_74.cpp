```cpp
#include <vector>
#include <string>

std::vector<std::string> total_match(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    int total_length1 = 0;
    for (const auto& str : vec1) {
        total_length1 += str.length();
    }

    int total_length2 = 0;
    for (const auto& str : vec2) {
        total_length2 += str.length();
    }

    if (total_length1 > total_length2) {
        return vec2;
    } else {
        return vec1;
    }
}
```