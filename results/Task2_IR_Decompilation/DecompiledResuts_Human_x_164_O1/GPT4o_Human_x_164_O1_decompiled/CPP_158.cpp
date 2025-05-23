```cpp
#include <string>
#include <vector>
#include <cstring>

std::string find_max(std::string& result, const std::vector<std::string>& vec) {
    size_t max_length = 0;
    size_t index = 0;
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].length() > max_length) {
            max_length = vec[i].length();
            index = i;
        }
    }
    
    if (max_length > 0) {
        result = vec[index];
    } else {
        result.clear();
    }
    
    return result;
}
```