#include <stdbool.h>

bool is_cube_root(int n) {
    int i = 0;
    int abs_n = n < 0 ? -n : n;
    while (i * i * i < abs_n) {
        i++;
    }
    return i * i * i <= abs_n;
}
