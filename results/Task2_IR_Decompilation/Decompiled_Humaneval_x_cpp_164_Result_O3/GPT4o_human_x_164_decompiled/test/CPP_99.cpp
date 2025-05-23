#include <string>
#include <cstdlib>
#include <cmath>

int closest_integer(const std::string &input) {
    const char *cstr = input.c_str();
    double value = strtod(cstr, nullptr);
    return static_cast<int>(round(value));
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
