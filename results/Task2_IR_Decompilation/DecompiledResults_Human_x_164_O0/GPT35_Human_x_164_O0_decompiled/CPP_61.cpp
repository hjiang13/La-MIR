```cpp
#include <string>

bool correct_bracketing(std::basic_string<char> &str) {
    bool result;
    int count = 0;
    int index = 0;
    
    while (index < str.length()) {
        char current_char = str[index];
        
        if (current_char == '(') {
            count++;
        } else if (current_char == ')') {
            count--;
        }
        
        if (count < 0) {
            result = false;
            break;
        }
        
        index++;
    }
    
    if (count == 0) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
```