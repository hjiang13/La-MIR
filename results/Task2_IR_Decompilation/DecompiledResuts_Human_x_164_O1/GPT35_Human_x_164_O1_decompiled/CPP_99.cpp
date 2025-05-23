```cpp
#include <string>
#include <cstdlib>

int closest_integer(std::basic_string<char> str) {
    const char* c_str = str.c_str();
    double num = stdtod(c_str, nullptr);
    double rounded_num = round(num);
    return static_cast<int>(rounded_num);
}
```