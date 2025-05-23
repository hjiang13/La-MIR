#include <string>
#include <cmath>

using namespace std;

int closest_integer(const string& str) {
    const char* c_str = str.c_str();
    double value = strtod(c_str, nullptr);
    double rounded = round(value);
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
