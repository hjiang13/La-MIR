```cpp
#include <string>

int hex_key(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>* param) {
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str = "2357BD";
    int count = 0;
    
    if (param->size() == 0) {
        return count;
    }
    
    for (int i = 0; i < param->size(); i++) {
        if (param->at(i) == str[count % str.size()]) {
            count++;
        }
    }
    
    return count;
}
```