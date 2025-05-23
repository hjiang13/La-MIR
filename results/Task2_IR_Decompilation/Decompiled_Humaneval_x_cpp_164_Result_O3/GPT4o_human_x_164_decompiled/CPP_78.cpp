```cpp
#include <string>
#include <cstring>

int hex_key(std::string str) {
    std::string tmp = "2357BD";
    int count = 0;
    size_t length = str.length();
    
    if (length == 0) {
        return count;
    }

    for (size_t i = 0; i < length; ++i) {
        if (i < tmp.length() && str[i] == tmp[i]) {
            count++;
        }
    }
    
    return count;
}
```