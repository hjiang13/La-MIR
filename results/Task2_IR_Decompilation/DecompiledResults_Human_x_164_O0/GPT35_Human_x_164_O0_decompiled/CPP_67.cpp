```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(std::basic_string<char>* str, int num) {
    std::basic_string<char> str1 = "1";
    std::basic_string<char> str2 = "1";
    int var1 = 0;
    int var2 = 0;
    
    while (var2 < str->size()) {
        char ch = (*str)[var2];
        int val = static_cast<int>(ch);
        
        if (val >= 48 && val <= 57) {
            var1++;
            if (var1 == 1) {
                str1 += ch;
            } else {
                str2 += ch;
            }
        }
        var2++;
    }
    
    int result1 = std::stoi(str1) - std::stoi(str2);
    
    return result1;
}
```