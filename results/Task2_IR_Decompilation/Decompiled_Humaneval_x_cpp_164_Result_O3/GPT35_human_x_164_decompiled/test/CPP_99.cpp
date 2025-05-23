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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (closest_integer("10") == 10);
    assert (closest_integer("14.5") == 15);
    assert (closest_integer("-15.5") == -16);
    assert (closest_integer("15.3") == 15);
    assert (closest_integer("0") == 0);
}
