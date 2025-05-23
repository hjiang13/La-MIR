```cpp
#include <iostream>
#include <string>
#include <vector>

std::string longest(std::string& result, const std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].size() > result.size()) {
            result = vec[i];
        }
    }
    return result;
}

int main() {
    std::vector<std::string> strings = {"short", "longer", "longest"};
    std::string longestString;
    longest(longestString, strings);
    std::cout << "Longest string: " << longestString << std::endl;
    return 0;
}
```