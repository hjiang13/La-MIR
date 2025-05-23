```cpp
#include <vector>
#include <string>
#include <algorithm>

void find_max(std::string& result, const std::vector<std::string>& vec) {
    result = "";
    for (const auto& str : vec) {
        for (char ch : str) {
            if (std::find(result.begin(), result.end(), ch) == result.end()) {
                result += ch;
            }
        }
        if (str.length() > result.length() || (str.length() == result.length() && str < result)) {
            result = str;
        }
    }
}
```