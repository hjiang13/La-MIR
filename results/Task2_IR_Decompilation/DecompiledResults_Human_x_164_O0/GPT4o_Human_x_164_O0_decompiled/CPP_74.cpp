```cpp
#include <vector>
#include <string>

void total_match(std::vector<std::string> &result, const std::vector<std::string> &vec1, const std::vector<std::string> &vec2) {
    int total_length_vec1 = 0;
    int total_length_vec2 = 0;
    int index1 = 0;

    while (index1 < vec1.size()) {
        total_length_vec1 += vec1[index1].length();
        index1++;
    }

    int index2 = 0;
    
    while (index2 < vec2.size()) {
        total_length_vec2 += vec2[index2].length();
        index2++;
    }

    if (total_length_vec1 > total_length_vec2) {
        result = vec1;
    } else {
        result = vec2;
    }
}
```