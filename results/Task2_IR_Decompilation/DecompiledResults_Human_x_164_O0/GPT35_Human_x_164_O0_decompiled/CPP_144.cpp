```cpp
#include <string>
#include <cstdlib>

bool simplify(std::string& str1, std::string& str2) {
    size_t pos1 = 0;
    size_t pos2 = 0;
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    
    while (pos1 < len1) {
        char ch = str1[pos1];
        if (ch == '/') {
            std::string sub1 = str1.substr(0, pos1);
            int num1 = std::atoi(sub1.c_str());
            
            std::string sub2 = str1.substr(pos1 + 1);
            int num2 = std::atoi(sub2.c_str());
            
            if (num1 % num2 == 0) {
                return true;
            } else {
                return false;
            }
        }
        pos1++;
    }
    
    return false;
}
```