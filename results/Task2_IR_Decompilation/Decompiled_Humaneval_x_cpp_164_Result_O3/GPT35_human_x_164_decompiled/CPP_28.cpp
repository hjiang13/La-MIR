```cpp
#include <string>
#include <vector>

void concatenate(std::string& result, std::vector<std::string>& input) {
    std::__cxx11::basic_string<char> temp;
    for (const auto& str : input) {
        temp.append(str);
    }
    result = temp;
}
```