```cpp
#include <vector>
#include <string>
#include <algorithm>

std::string find_max(std::string& max_str, const std::vector<std::string>& vec) {
    max_str = "";
    size_t max_length = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        const std::string& current = vec[i];
        if (current.length() > max_length) {
            max_length = current.length();
            max_str = current;
        }
    }

    return max_str;
}
```