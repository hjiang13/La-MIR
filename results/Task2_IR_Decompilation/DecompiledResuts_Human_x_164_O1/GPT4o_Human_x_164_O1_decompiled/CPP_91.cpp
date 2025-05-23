```cpp
#include <string>

int is_bored(const std::string& str) {
    size_t length = str.size();
    if (length == 0) {
        return 0;
    }

    int count = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = str[i];
        if (c == ' ') {
            count++;
        } else if (c == 'I') {
            count += 1; // Assuming some condition is applied here
        } else if (c == '.') {
            break; // Assuming some termination condition
        } else if (c == '?') {
            break; // Assuming some termination condition
        }
    }
    
    return count;
}
```