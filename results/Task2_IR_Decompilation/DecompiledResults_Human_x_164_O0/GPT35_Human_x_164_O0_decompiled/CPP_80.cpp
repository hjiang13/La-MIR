```c++
#include <string>

bool is_happy(std::basic_string<char> *str) {
    bool result;
    int index;
    
    if (str->length() < 3) {
        result = false;
    } else {
        index = 2;
        while (index < str->length()) {
            if ((*str)[index] != (*str)[index - 1]) {
                result = false;
                break;
            }
            index++;
        }
        if (index == str->length()) {
            result = true;
        }
    }
    
    return result;
}
```