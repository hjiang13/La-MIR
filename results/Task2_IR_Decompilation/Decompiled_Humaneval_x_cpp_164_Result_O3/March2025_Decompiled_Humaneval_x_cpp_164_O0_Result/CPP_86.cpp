```cpp
#include <string>
#include <algorithm>

std::string anti_shuffle(const std::string& input) {
    std::string result;
    std::string temp = input;
    std::sort(temp.begin(), temp.end());
    result += temp;
    return result;
}
```