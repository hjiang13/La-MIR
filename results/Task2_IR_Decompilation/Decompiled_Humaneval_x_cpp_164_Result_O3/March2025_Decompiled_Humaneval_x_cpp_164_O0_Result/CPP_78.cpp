```cpp
#include <string>
#include <algorithm>

int hex_key(const std::string& input) {
    std::string str = "2357BD";
    int count = 0;
    int index = 0;

    while (index < input.length()) {
        auto it = std::find(str.begin(), str.end(), input[index]);
        if (it != str.end()) {
            count++;
        }
        index++;
    }

    return count;
}
```