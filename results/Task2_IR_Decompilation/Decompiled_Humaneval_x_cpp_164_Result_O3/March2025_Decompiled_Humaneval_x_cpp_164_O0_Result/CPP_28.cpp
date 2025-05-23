```cpp
#include <vector>
#include <string>

extern "C" void concatenate(std::string& result, const std::vector<std::string>& vec) {
    result = "";
    for (const auto& str : vec) {
        result += str;
    }
}
```