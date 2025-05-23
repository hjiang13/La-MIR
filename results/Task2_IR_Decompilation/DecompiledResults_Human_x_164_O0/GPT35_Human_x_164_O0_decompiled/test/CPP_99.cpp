#include <string>
#include <cstdlib>

int closest_integer(std::basic_string<char> *str) {
    double val;
    char *cstr = str->c_str();
    val = atof(cstr);
    val = round(val);
    return static_cast<int>(val);
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
