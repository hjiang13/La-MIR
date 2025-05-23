```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void parse_music(std::vector<std::string>& vec, const std::string& input) {
    std::string temp;
    if (input.empty()) {
        return;
    }

    size_t length = input.size();
    if (length > 15) {
        temp.resize(length);
        std::memcpy(&temp[0], input.c_str(), length);
    } else {
        if (length == 1) {
            temp.resize(1);
            temp[0] = input[0];
        } else {
            temp.resize(length);
            std::memcpy(&temp[0], input.c_str(), length);
        }
    }

    vec.push_back(temp);
    vec.back().push_back('\0');
}
```