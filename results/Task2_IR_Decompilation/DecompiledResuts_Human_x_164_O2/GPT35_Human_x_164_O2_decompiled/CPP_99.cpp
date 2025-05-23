```cpp
#include <string>

extern "C" {
    double llvm.round.f64(double);
    double strtod(const char*, char**);
    int __gxx_personality_v0(...);
}

int closest_integer(std::basic_string<char> str) {
    const char* ptr = &str._M_dataplus._M_p;
    double val = strtod(ptr, nullptr);
    double rounded = llvm.round.f64(val);
    return static_cast<int>(rounded);
}
```