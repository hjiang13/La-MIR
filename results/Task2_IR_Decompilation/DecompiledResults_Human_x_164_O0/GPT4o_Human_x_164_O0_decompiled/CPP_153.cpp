```cpp
#include <string>
#include <vector>

std::string Strongest_Extension(std::string str1, std::vector<std::string> vec) {
    std::string result;
    int count = 0;
    int index = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (index < str1.length() && vec[i].length() > 0) {
            char ch = str1[index];
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                count++;
            }
            index++;
        }
    }

    result = str1;
    return result;
}
```