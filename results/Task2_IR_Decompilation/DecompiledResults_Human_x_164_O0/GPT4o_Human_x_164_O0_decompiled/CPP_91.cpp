```cpp
#include <string>

int is_bored(const std::string& str) {
    int count = 0;
    int result = 0;
    bool flag = true;

    while (count < str.length()) {
        char ch = str[count];
        if (ch == 32) {
            if (flag) {
                result = 1;
            }
        } else if (ch == 73) {
            flag = false;
            result = 1;
        } else if (ch == 46 || ch == 63 || ch == 33) {
            result = 1;
        }
        count++;
    }
    
    return result;
}
```