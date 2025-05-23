#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int closest_integer(const char* str) {
    double num = strtod(str, NULL);
    return (int)round(num);
}
