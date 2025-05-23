#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int closest_integer(const char* str) {
    double num = strtod(str, NULL);
    return (int)round(num);
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
