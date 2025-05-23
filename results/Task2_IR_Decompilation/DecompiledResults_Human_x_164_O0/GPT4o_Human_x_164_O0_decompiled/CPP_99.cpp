```cpp
#include <string>
#include <cstdlib>
#include <cmath>

int closest_integer(const std::string& str) {
    const char* c_str = str.c_str();
    double value = atof(c_str);
    return static_cast<int>(round(value));
}
```