#include <stdbool.h>

bool iscuberi(int i) {
    int abs_i = (i < 0) ? -i : i;
    int j = 0;
    while (true) {
        int j_cubed = j * j * j;
        if (j_cubed >= abs_i) break;
        j++;
    }
    return j_cubed <= abs_i;
}
