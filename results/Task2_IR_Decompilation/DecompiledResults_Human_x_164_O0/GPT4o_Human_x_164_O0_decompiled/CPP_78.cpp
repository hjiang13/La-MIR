```cpp
#include <iostream>
#include <string>
#include <algorithm>

int hex_key(const std::string& str) {
    std::string hex_string = "2357BD";
    int count = 0;
    auto it = str.begin();
    auto end = str.end();

    while (it != end) {
        auto found = std::find(it, end, *hex_string.begin());
        if (found != end) {
            ++count;
            it = found + 1;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    std::string test_string = "Your input string here";
    int result = hex_key(test_string);
    std::cout << result << std::endl;
    return 0;
}
```