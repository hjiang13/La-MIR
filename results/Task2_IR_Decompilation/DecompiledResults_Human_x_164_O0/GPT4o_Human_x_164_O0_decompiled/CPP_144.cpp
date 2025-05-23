```cpp
#include <string>
#include <cstdlib>

bool simplify(std::string str1, std::string str2) {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    
    while (count1 < str1.size()) {
        if (str1[count1] == '/') {
            std::string substr1 = str1.substr(0, count1);
            count2 = atoi(substr1.c_str());
            break;
        }
        count1++;
    }
    
    while (count1 < str1.size()) {
        count1++;
        if (count1 >= str1.size()) break;
        if (str1[count1] == '/') {
            std::string substr1 = str1.substr(count1 + 1);
            count3 = atoi(substr1.c_str());
            break;
        }
    }
    
    while (count2 < str2.size()) {
        if (str2[count2] == '/') {
            std::string substr2 = str2.substr(0, count2);
            count4 = atoi(substr2.c_str());
            break;
        }
        count2++;
    }

    if (count3 == 0 || count4 == 0) return false;

    return (count2 * count3) % (count4 * count4) == 0;
}
```