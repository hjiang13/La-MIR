```cpp
#include <iostream>
#include <string>
#include <cstdarg>

void string_sequence(std::string &s, int count) {
    if (count < 1) {
        return;
    }
    s.append(1, '0');
    for (int i = 1; i < count; ++i) {
        s.append("%d", i);
    }
}

int main() {
    std::string result;
    string_sequence(result, 5);
    std::cout << result << std::endl;
    return 0;
}
```