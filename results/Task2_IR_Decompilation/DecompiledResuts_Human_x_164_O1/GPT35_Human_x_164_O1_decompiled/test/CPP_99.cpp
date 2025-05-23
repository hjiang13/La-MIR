```cpp
#include <string>
#include <cstdlib>

int closest_integer(std::basic_string<char> str) {
    const char* c_str = str.c_str();
    double num = stdtod(c_str, nullptr);
    double rounded_num = round(num);
    return static_cast<int>(rounded_num);
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
