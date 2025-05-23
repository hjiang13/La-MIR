```cpp
#include <string>
#include <stdexcept>

std::string rounded_avg(int a, int b) {
    if (a > b) {
        return std::string("-1");
    } else {
        int avg = (a + b) / 2;
        return std::to_string(avg % 2);
    }
}
```