```cpp
#include <string>
#include <cstdlib>
#include <cmath>

int closest_integer(const std::string &input) {
    const char *cstr = input.c_str();
    double value = strtod(cstr, nullptr);
    return static_cast<int>(round(value));
}
```