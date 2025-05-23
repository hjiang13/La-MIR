```cpp
#include <string>
#include <cstdlib>
#include <cmath>

int closest_integer(const std::string& str) {
    const char* c_str = str.c_str();
    double value = strtod(c_str, nullptr);
    return static_cast<int>(round(value));
}
```