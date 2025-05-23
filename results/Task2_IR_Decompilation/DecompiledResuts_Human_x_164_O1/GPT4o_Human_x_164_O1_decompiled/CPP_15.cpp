```cpp
#include <iostream>
#include <string>
#include <cstdarg>
#include <cstring>

void string_sequence(int n) {
    std::string str;
    for (int i = 0; i < n; ++i) {
        if (i < 1) {
            str.append("0");
        } else {
            char buffer[3];
            snprintf(buffer, sizeof(buffer), "%d", i);
            str.append(buffer);
        }
    }
    std::cout << str << std::endl;
}

int main() {
    string_sequence(10);
    return 0;
}
```