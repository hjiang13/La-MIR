```cpp
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

std::string find_max(std::string& result, const std::vector<std::string>& vec) {
    size_t maxIndex = 0;
    size_t maxLength = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].length() > maxLength) {
            maxLength = vec[i].length();
            maxIndex = i;
        }
    }

    if (maxLength > 0) {
        result = vec[maxIndex];
    } else {
        result.clear();
    }

    return result;
}
```