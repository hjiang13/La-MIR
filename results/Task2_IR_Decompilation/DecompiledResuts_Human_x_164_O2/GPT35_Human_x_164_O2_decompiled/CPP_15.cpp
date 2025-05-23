```cpp
#include <iostream>
#include <string>

void string_sequence(std::__cxx11::basic_string& s, int n) {
    s.clear();
    s += '0';

    std::__cxx11::basic_string temp;
    temp += s;

    for (int i = 1; i < n; i++) {
        temp += s;
    }

    s = temp;
}

int main() {
    std::__cxx11::basic_string s;
    string_sequence(s, 5);

    std::cout << s << std::endl;

    return 0;
}
```