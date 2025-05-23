```cpp
#include <vector>
#include <string>
#include <stdexcept>

void parse_music(std::vector<int>& vec, const std::string& str) {
    std::string temp;
    vec.clear();

    if (!str.empty()) {
        if (str == "o") {
            vec.push_back(4);
        } else if (str == "o|") {
            vec.push_back(2);
        } else if (str == ".|") {
            vec.push_back(1);
        } else {
            vec.push_back(0);
        }
    }
}
```