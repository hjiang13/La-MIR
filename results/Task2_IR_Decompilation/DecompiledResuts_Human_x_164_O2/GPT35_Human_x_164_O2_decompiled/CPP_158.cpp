```cpp
#include <vector>
#include <string>

void find_max(std::__cxx11::basic_string* result, std::vector<std::__cxx11::basic_string>* input) {
    std::__cxx11::basic_string* max_str = nullptr;
    for (auto str : *input) {
        if (max_str == nullptr || str.size() > max_str->size()) {
            max_str = &str;
        }
    }
    *result = *max_str;
}
```