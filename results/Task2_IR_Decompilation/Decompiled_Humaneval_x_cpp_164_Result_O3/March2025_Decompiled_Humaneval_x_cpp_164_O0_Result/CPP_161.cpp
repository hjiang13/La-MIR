```cpp
#include <string>
#include <algorithm>
#include <stdexcept>

void solve(std::string& result, const std::string& input) {
    std::string temp;
    std::allocator<char> alloc;
    try {
        temp = std::string("", alloc);
    } catch (...) {
        throw;
    }

    int count = 0;
    for (int i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        } else if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else {
            ++count;
        }
        temp += c;
    }

    if (count == input.length()) {
        result = std::string(input.rbegin(), input.rend(), alloc);
    } else {
        result = std::move(temp);
    }
}
```