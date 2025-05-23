```c++
#include <string>
#include <cstdlib>

int closest_integer(std::string str) {
    const char* c_str = str.c_str();
    double value = strtod(c_str, nullptr);
    double rounded = llvm.round.f64(value);
    int result = static_cast<int>(rounded);
    return result;
}
```