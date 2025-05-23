```cpp
#include <string>
#include <cstdlib>
#include <stdexcept>

bool simplify(std::string str1, std::string str2) {
    size_t pos1 = str1.size();
    size_t pos2 = str2.size();
    
    if (pos1 == 0) {
        return pos2 == 0;
    }

    size_t i = 0;
    while (i < pos1) {
        if (str1[i] == '/') {
            i++;
            continue;
        }
        size_t j = 0;
        while (j < pos2 && j < pos1) {
            if (str2[j] == '/') {
                j++;
                continue;
            }
            if (str1[i] == str2[j]) {
                break;
            }
            j++;
        }
        if (j == pos2) {
            return false;
        }
        i++;
    }
    return true;
}
```