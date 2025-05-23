```cpp
#include <vector>
#include <string>
#include <cstring>

void total_match(std::vector<std::string>& result, const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    std::string str1, str2;
    size_t index1 = 0, index2 = 0;

    while (index1 < vec1.size() && index2 < vec2.size()) {
        str1 = vec1[index1];
        str2 = vec2[index2];

        if (str1 == str2) {
            result.push_back(str1);
            index1++;
            index2++;
        } else {
            if (str1 < str2) {
                index1++;
            } else {
                index2++;
            }
        }
    }
}
```