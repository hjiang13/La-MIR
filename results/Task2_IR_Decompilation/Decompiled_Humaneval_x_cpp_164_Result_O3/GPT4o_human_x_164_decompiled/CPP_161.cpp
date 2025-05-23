```cpp
#include <string>

void solve(std::string& result, const std::string& input) {
    uint64_t size = 0;
    uint64_t* sizePtr = &size;
    std::string temp;

    if (input.size() == 0) {
        result = temp;
        return;
    }

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            temp += ch + 32;
        } else if (ch >= 'a' && ch <= 'z') {
            temp += ch - 32;
        } else {
            temp += ch;
        }
    }

    size = temp.size();
    result = temp;
}
```