```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void find_max(std::string& result, const std::vector<std::string>& vec) {
    size_t maxIndex = 0;
    size_t maxLength = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].size() > maxLength) {
            maxLength = vec[i].size();
            maxIndex = i;
        }
    }

    result = vec[maxIndex];
}

int main() {
    std::vector<std::string> vec = {"short", "longer", "longest"};
    std::string maxString;
    find_max(maxString, vec);
    std::cout << "Max string: " << maxString << std::endl;
    return 0;
}
```