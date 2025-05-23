```cpp
#include <string>

bool is_nested(std::__cxx11::basic_string<char>* str) {
    if (str->size() == 0) {
        return false;
    }
    
    int count = 0;
    
    for (size_t i = 0; i < str->size(); ++i) {
        char c = (*str)[i];
        
        if (c == '[') {
            count++;
        } else if (c == ']') {
            count--;
        }
        
        if (count > 0) {
            return true;
        }
    }
    
    return false;
}
```