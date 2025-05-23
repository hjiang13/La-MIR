```cpp
#include <string>
#include <cstdlib>

int closest_integer(std::basic_string<char> *str) {
    double val;
    char *cstr = str->c_str();
    val = atof(cstr);
    val = round(val);
    return static_cast<int>(val);
}
```