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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (closest_integer("10") == 10);
    assert (closest_integer("14.5") == 15);
    assert (closest_integer("-15.5") == -16);
    assert (closest_integer("15.3") == 15);
    assert (closest_integer("0") == 0);
}
