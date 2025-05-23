```cpp
#include <string>

void fix_spaces(std::string& dest, std::string& source) {
    dest = "";
    int i = 0;
    int length = source.length();
    
    while (i < length) {
        char c = source[i];
        
        if (c == ' ') {
            int count = 0;
            while (i < length && source[i] == ' ') {
                count++;
                i++;
            }
            
            if (count == 1) {
                dest += "__";
            } else if (count == 2) {
                dest += "_";
            } else {
                dest += " ";
            }
        } else {
            dest += c;
            i++;
        }
    }
}
```