```cpp
#include <string>
#include <vector>

void find_max(std::string& result, std::vector<std::string>& input) {
    std::string max_str;
    int max_length = 0;

    for (const std::string& str : input) {
        if (str.size() > max_length) {
            max_length = str.size();
            max_str = str;
        }
    }

    result = max_str;
}
```