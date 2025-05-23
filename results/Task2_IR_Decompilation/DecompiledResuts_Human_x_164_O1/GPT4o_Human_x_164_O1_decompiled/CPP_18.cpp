```cpp
#include <string>
#include <stdexcept>
#include <cstring>

int how_many_times(const std::string& str1, const std::string& str2) {
    if (str1.size() == 0) {
        return 0;
    }

    size_t count = 0;
    size_t pos = 0;
    size_t str2_size = str2.size();
    
    while ((pos = str1.find(str2, pos)) != std::string::npos) {
        count++;
        pos += str2_size;
    }

    return count;
}
```