```cpp
#include <vector>
#include <string>

void concatenate(std::string &result, const std::vector<std::string> &vec) {
    result.clear();
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
    }
}
```