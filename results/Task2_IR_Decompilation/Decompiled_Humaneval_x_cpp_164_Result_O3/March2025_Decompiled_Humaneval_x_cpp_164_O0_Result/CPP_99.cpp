```cpp
#include <string>
#include <cmath>
#include <cstdlib>

int closest_integer(const std::string& str) {
    double value = std::atof(str.c_str());
    return static_cast<int>(std::round(value));
}
```