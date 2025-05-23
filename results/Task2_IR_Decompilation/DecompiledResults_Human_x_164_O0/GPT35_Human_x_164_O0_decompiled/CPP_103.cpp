```cpp
#include <string>
#include <stdexcept>

std::__cxx11::basic_string rounded_avg(int i, int j) {
    std::__cxx11::basic_string result;
    
    if (i > j) {
        result = "-1";
    } else {
        int avg = (i + j) / 2;
        result = std::to_string(avg % 2);
    }
    
    return result;
}

int main() {
    int a = 10;
    int b = 20;
    
    std::__cxx11::basic_string result = rounded_avg(a, b);
    
    return 0;
}
```