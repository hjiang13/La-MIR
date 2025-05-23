```cpp
#include <vector>
#include <string>
#include <cstring>

void total_match(std::vector<std::string>& result, const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    size_t index1 = 0;
    size_t index2 = 0;
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    while (index1 < size1 && index2 < size2) {
        if (vec1[index1] == vec2[index2]) {
            result.push_back(vec1[index1]);
            index1++;
            index2++;
        } else {
            index1++;
        }
    }

    while (index2 < size2) {
        result.push_back(vec2[index2]);
        index2++;
    }
}
```