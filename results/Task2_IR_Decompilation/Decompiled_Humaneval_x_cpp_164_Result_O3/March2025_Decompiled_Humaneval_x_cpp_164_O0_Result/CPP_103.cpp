```cpp
#include <string>
#include <stdexcept>

std::string rounded_avg(int a, int b) {
    if (a > b) {
        return "-1";
    } else {
        int sum = a + b;
        int avg = sum / 2;
        std::string result;
        if (avg > 0) {
            int remainder = avg % 2;
            result = std::to_string(remainder) + std::string();
        }
        return result;
    }
}
```