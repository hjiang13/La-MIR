#include <iostream>
#include <string>

using namespace std;

int closest_integer(string str) {
    double num = atof(str.c_str());
    double rounded = llvm.round.f64(num);
    return (int)rounded;
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
