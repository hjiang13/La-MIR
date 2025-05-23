```cpp
#include <string>
#include <vector>
#include <algorithm>

std::string Strongest_Extension(const std::string& input, std::vector<std::string> vec) {
    std::string result;
    int max_count = -1000;
    int current_count = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < vec[i].length(); ++j) {
            char c = vec[i][j];
            if (c >= 'A' && c <= 'Z') {
                ++count;
            } else if (c >= 'a' && c <= 'z') {
                --count;
            }
        }
        if (count > max_count) {
            max_count = count;
            result = vec[i];
        }
    }

    return input + "." + result;
}
```