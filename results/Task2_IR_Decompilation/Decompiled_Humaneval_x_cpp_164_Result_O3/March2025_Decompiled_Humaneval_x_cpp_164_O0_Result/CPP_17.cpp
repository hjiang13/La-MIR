```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

std::vector<int> parse_music(const std::string& input) {
    std::vector<int> result;
    std::string temp;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == ' ') {
            if (temp == "o") {
                result.push_back(4);
            } else if (temp == "o|") {
                result.push_back(2);
            } else if (temp == ".|") {
                result.push_back(1);
            }
            temp.clear();
        } else {
            temp += c;
        }
    }
    return result;
}
```