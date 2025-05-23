```cpp
#include <string>
#include <iostream>

int count_upper(const std::string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string str = "AEIOU";
    std::cout << "Uppercase letters count: " << count_upper(str) << std::endl;
    return 0;
}
```